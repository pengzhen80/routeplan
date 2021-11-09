#include "CallCarServer.h"
#include <iostream>

//calculate the len of message by four byte of beginning
int Lenth_Message(char *buff)
{
    char tmp[4];
    for (int i = 0; i < 4; i++)
    {
        tmp[i] = buff[i];
    }
    int result = *((int *)tmp);
    return result;
}

//sNetwork_eCDNM_C2S_CAR_STATUS
void DealMessage(char *message)
{
    struct sNetwork_eCDNM_C2S_CAR_STATUS *msg = reinterpret_cast<struct sNetwork_eCDNM_C2S_CAR_STATUS *>(message);
    printf("car speead is %d\n", msg->iMotorSpeed);
}

// void SendCarGo(int conn)
// {
//     struct SendCarGo message;

//     message.message.iCarID = 7;
//     message.message.iSmallPartDataCount = 1;
//     message.message.iCount = 2;
//     message.message.RouteDividedIntoSmallPartDataArray[0].ui8StartNodeID = -1;
//     message.message.RouteDividedIntoSmallPartDataArray[0].ui8EndNodeID = -1;
//     message.message.ui8NodeIDArray[0] = -1;
//     message.message.ui8NodeIDArray[1] = -1;

//     message.message.RouteDividedIntoSmallPartDataArray[0].i8LoopTransferType = 3;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i8AngleType = 0;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i16Distance[0] = 10000;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i16Distance[1] = 10000;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i16Acc[0] = 25;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i16Acc[1] = 25;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i16Speed[0] = 50;
//     message.message.RouteDividedIntoSmallPartDataArray[0].i16Speed[1] = 50;

//     message.lenth = sizeof(message.message);

//     write(conn, (char *)(&message), sizeof(message));
// }

// void *CallCarServer::thread_accept(void *data)
void CallCarServer::thread_accept()
{
#if 0
    std::mutex mtx;

    // int conn = *((int *)data);
    printf("accept thread %d\n", std::this_thread::get_id());

    //deal with the first message
    char recvbuf[BUFF_SIZE];
    memset(recvbuf, 0, sizeof(recvbuf));

    int num = read(conn_, recvbuf, sizeof(recvbuf));

    //printf("first message length is %d\n",num);
    int len = Lenth_Message(recvbuf);

    char *message = new char(len);
    for (int i = 0; i < len; i++)
    {
        message[i] = recvbuf[i + 4];
    }

    DealMessage(message);
    delete message;

    //send the first order

    struct SendBuf sendbuf;
    sendbuf.lenth = sizeof(sendbuf.message);
    sendbuf.message.fSendHardwareDataToServerTC = 1;
    sendbuf.message.iVersion = CAR_DRIVING_SERVER_NETWORK_MESSAGE_VERSION;
    sendbuf.message.fMotorWarningAsErrorTC = 10; //while motor keeps warning for a while treat it as error
    sendbuf.message.fNodeToNodeTCStright = 10;
    sendbuf.message.fNodeToNodeTC90 = 10;
    sendbuf.message.fNodeToNodeTC180 = 10;
    printf("sendbuf is %d\n", sizeof(sendbuf));

    mtx.lock();
    write(conn_, (char *)(&sendbuf), sizeof(sendbuf));
    mtx.unlock();

    // if (!que_send_.empty())
    // {
    //     write(conn_, (char *)(&que_send_.front()), sizeof(que_send_.front()));
    //     int len = que_send_.front().lenth;
    //     printf("send message len is %d\n", len);
    // }

    //send_message();
    write(conn_, (char *)(&m_cargo_), sizeof(m_cargo_));

#endif

#if 0
    while (true)
    {
        sleep(1);

        std::cout << "send buf size is " << sizeof(m_cargo_simulator_) << std::endl;
        //for(int i=0;i<m_cargo_simulator_.siz)
        write(conn_, (char *)(&m_cargo_simulator_), sizeof(m_cargo_simulator_));
    }
#endif
#if 1 //receive s_id and e_id

    char recvbuf[BUFF_SIZE];
    while (true)
    {
        //sleep(1);
        usleep(10);
        memset(recvbuf, 0, sizeof(recvbuf));
        int num = read(conn_, recvbuf, sizeof(recvbuf));
        if (num <= 0)
        {
            continue;
        }
        //debug
        //std::cout << "receive buf size is : " << num << std::endl;
        //every 12 byte is a message
        m_mutex_simulator_que_receive_.lock();
        for (int i = 0; i < (num / sizeof(Simulator_SidEid)); i++)
        {
            Simulator_SidEid *message = reinterpret_cast<Simulator_SidEid *>(&recvbuf[i * sizeof(Simulator_SidEid)]);
            //std::cout << "start id is " << message->s_id << ",end id is " << message->e_id << std::endl;
            std::vector<int> vec;
            vec.push_back(message->msgtype);
            vec.push_back(message->car_id);
            vec.push_back(message->s_id);
            vec.push_back(message->e_id);
            m_simulator_que_receive_.push(vec);
        }
        m_mutex_simulator_que_receive_.unlock();

    }

#endif

#if 0
    char recvbuf[BUFF_SIZE];
    while (true)
    {
        sleep(1);

        memset(recvbuf, 0, sizeof(recvbuf));

        int num = read(conn_, recvbuf, sizeof(recvbuf));

        if (num <= 0)
        {
            continue;
        }
        printf("message length is %d\n", num);

        //take the length of message
        //int len = Lenth_Message(recvbuf);
        //len = num-4;

        char *message = new char(num - 4);
        for (int i = 0; i < len; i++)
        {
            message[i] = recvbuf[i + 4];
        }

        // DealMessage(message);

        ReceiveBuf *recvbuf = reinterpret_cast<ReceiveBuf *>(message);
        std::cout<< recvbuf->message.iCarID<<std::endl;

        delete (message);
        //SendCarGo(conn);
    }
#endif
    close(conn_);
}

// void* CallCarServer::DealQueue(void* data)
#if 0
void CallCarServer::DealQueue()
{   
    //int conn = *((int *)data);
    while(b_receive_)
    {
        //sleep(1);
        que_receive_mutex_.lock();
        if(!que_receive_.empty())
        {
            //do something with this
            //int i = que_receive_.front()->message.iCarID;
            //std::cout<<"car id is "<<que_receive_.front()->message.iCarID<<std::endl;
            que_receive_.pop();
        }
        que_receive_mutex_.unlock();

        que_send_mutex_.lock();
        if(!que_send_.empty()&&conn_>=0)
        {
            //do something with this;
            struct SendCarGo data;
            data.message = que_send_.front()->message;
            data.lenth = sizeof(data.message);
            write(conn_,(char*)(&data),sizeof(data));
            printf("send message is %d\n",data.lenth);
            que_send_.pop();
        }
        que_send_mutex_.unlock();
    }
}
#endif

void CallCarServer::send_message(std::vector<int> vec_route)
{
    // struct SendCarGo message;

    // message.lenth = sizeof(message.message);

    // message.message.iCarID = 7;
    // message.message.iSmallPartDataCount = 1;
    // message.message.iCount = 2;
    // message.message.RouteDividedIntoSmallPartDataArray[0].ui8StartNodeID = -1;
    // message.message.RouteDividedIntoSmallPartDataArray[0].ui8EndNodeID = -1;
    // message.message.ui8NodeIDArray[0] = -1;
    // message.message.ui8NodeIDArray[1] = -1;

     //message.message.RouteDividedIntoSmallPartDataArray[0].i8LoopTransferType = 3;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i8AngleType = 0;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i16Distance[0] = 10000;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i16Distance[1] = 10000;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i16Acc[0] = 25;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i16Acc[1] = 25;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i16Speed[0] = 50;
    // message.message.RouteDividedIntoSmallPartDataArray[0].i16Speed[1] = 50;

#if 0
    struct SendCarGo sendbuf;

    sendbuf.message.iCount = vec_route.size();
    sendbuf.message.iSmallPartDataCount = 1;
    sendbuf.message.iCarID = 7;

    sendbuf.message.ui8NodeIDArray[0] = -1;
    sendbuf.message.ui8NodeIDArray[1] = -1;

    for (int i = 0; i < vec_route.size(); i++)
    {
        sendbuf.message.ui8NodeIDArray[i] = vec_route[i];
    }

    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i8AngleType = 3;
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i16Speed[0] = 20;
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i16Speed[1] = 20;
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i16Acc[0] = 10;
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i16Acc[1] = 10;
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].ui8StartNodeID = vec_route[0];
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].ui8EndNodeID = vec_route[vec_route.size() - 1];
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i16Distance[0] = distance;
    sendbuf.message.RouteDividedIntoSmallPartDataArray[0].i16Distance[1] = distance;

    sendbuf.lenth = sizeof(sendbuf.message);

    //write(conn_, (char *)(&sendbuf), sizeof(sendbuf));
    m_cargo_ = sendbuf;
#endif

    SendCarGo_Simulator sendbuf;
    //debug
    std::cout << "send buf is : ";
    for (int i = 0; i < vec_route.size(); i++)
    {
        sendbuf.route[i] = vec_route[i];
        std::cout << vec_route[i] << " ";
    }
    std::cout << std::endl;
    sendbuf.size = vec_route.size();

    // m_mutex_simulator.lock();
    // m_cargo_simulator_ = sendbuf;
    // m_mutex_simulator.unlock();
    write(conn_, (char *)(&sendbuf), sizeof(sendbuf));
}

void CallCarServer::Init()
{
    int listenfd;

    if ((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        ERR_EXIT("ERROR");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(CAR_DRIVING_SERVER_NETWORK_TARGET_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)))
    {
        ERR_EXIT("SETSOCKOPT");
    }
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        ERR_EXIT("ERROR");
    }
    if (listen(listenfd, SOMAXCONN) < 0)
    {
        ERR_EXIT("LISTEN");
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
            ERR_EXIT("accept");
        }

        printf("ip = %s, port = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        conn_ = conn;

        std::thread t_receive(&CallCarServer::thread_accept, this);
        t_receive.detach();
    }
    close(listenfd);
}

struct SendCarGo *CallCarServer::MakeSendBufByRoute(std::vector<int> vec_route, float distance)
{
    struct SendCarGo *sendbuf = new SendCarGo();

    sendbuf->message.iCount = vec_route.size();
    sendbuf->message.iSmallPartDataCount = 1;
    sendbuf->message.iCarID = 7;

    for (int i = 0; i < vec_route.size(); i++)
    {
        sendbuf->message.ui8NodeIDArray[i] = vec_route[i];
    }

    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i8AngleType = 3;
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i16Speed[0] = 10;
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i16Speed[1] = 10;
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i16Acc[0] = 10;
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i16Acc[1] = 10;
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].ui8StartNodeID = vec_route[0];
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].ui8EndNodeID = vec_route[vec_route.size() - 1];
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i16Distance[0] = distance;
    sendbuf->message.RouteDividedIntoSmallPartDataArray[0].i16Distance[1] = distance;

    sendbuf->lenth = sizeof(sendbuf->message);

    return sendbuf;
}

bool CallCarServer::has_message()
{
    // if (m_simulator_receive_.size() > 0)
    //     return true;
    if (m_simulator_que_receive_.size() > 0)
        return true;
    return false;
}

std::vector<std::vector<int>> CallCarServer::get_message()
{
    // std::vector<int> result;
    // result = m_simulator_receive_;

    // m_mutex_simulator_receive_.lock();
    // m_simulator_receive_.clear();
    // m_mutex_simulator_receive_.unlock();

    std::vector<std::vector<int>> result;
    m_mutex_simulator_receive_.lock();
    while (!m_simulator_que_receive_.empty())
    {
        
        result.push_back(m_simulator_que_receive_.front());
        m_simulator_que_receive_.pop();
    }
    m_mutex_simulator_receive_.unlock();

    return result;
}