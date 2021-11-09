#include "TinkerBoardServer.h"
#include <iostream>

// void *CallCarServer::thread_accept(void *data)
void TinkerBoardServer::thread_accept()
{
    char recvbuf[BUFF_SIZE];
    while (true)
    {

        usleep(10);
        memset(recvbuf, 0, sizeof(recvbuf));
        int num = read(conn_, recvbuf, sizeof(recvbuf));
        if (num <= 0)
        {
            continue;
        }

        for (int i = 0; i < (num / sizeof(Message_SendTo_Server)); i++)
        {
            Message_SendTo_Server *message = reinterpret_cast<Message_SendTo_Server *>(&recvbuf[i * sizeof(Message_SendTo_Server)]);
            std::cout << message->type << std::endl;
            //msgs_receive_.push_back(*message);
            sig_msg(std::move(*message));
        }
        
    }

}

void TinkerBoardServer::Init()
{
    int listenfd;

    if ((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        std::cout << "ERROR";
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(TINKERBOARD_SERVER_NETWORK_TARGET_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)))
    {
        std::cout << ("SETSOCKOPT");
    }
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        std::cout << ("ERROR");
    }
    if (listen(listenfd, SOMAXCONN) < 0)
    {
        std::cout << ("LISTEN");
    }
    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    int conn;
    char sendbuf[256];
    //std::vector<in_addr> vec_ip;
    while (true)
    {
        conn = accept(listenfd, (struct sockaddr *)&peeraddr, &peerlen);
        if (conn < 0)
        {
            std::cout << ("accept");
        }

        printf("ip = %s, port = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        conn_ = conn;

        std::thread t_receive(&TinkerBoardServer::thread_accept, this);
        t_receive.detach();
    }
    close(listenfd);
}

void TinkerBoardServer::slot_send_msg(Message_From_Server msg)
{
    std::cout << "TinkerBoardServer: send a msg "<<sizeof(msg)<<",data size is "<<msg.size<<std::endl;;
    write(conn_, (char *)(&msg), sizeof(msg));
}
// std::vector<Message_SendTo_Server> TinkerBoardServer::Get_message()
// {
//     std::vector<Message_SendTo_Server> result;

//     std::lock_guard<std::mutex> lock(mutex_msg_receive_);
//     for(auto msg : msgs_receive_)
//     {
//         result.push_back(msg);
//     }
//     msgs_receive_.clear();
//     return result;
// }

// bool TinkerBoardServer::Has_message()
// {
//     return !msgs_receive_.empty();
// }

// void TinkerBoardServer::Send_message(std::vector<Message_From_Server> msgs_send)
// {
//     for(auto msg:msgs_send)
//     {
//         write(conn_, (char *)(&msg), sizeof(msg));
//     }
// }