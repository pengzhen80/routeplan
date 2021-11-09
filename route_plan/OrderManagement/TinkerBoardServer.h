#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <string>
#include <memory>
#include <vector>
#include <thread>
#include <iostream>
#include <mutex>
#include <queue>
#include <sys/epoll.h>

#include"Protocol_SendMealSystem.h"
#include "Core/Core_Connect/core_connect.h"

using Protocol_SendMealSystem::Message_From_Server;
using Protocol_SendMealSystem::Message_SendTo_Server;

using Core_Connect::Signal;
using Core_Connect::Slot;

#ifndef TINKERBOARDSERVER
#define TINKERBOARDSERVER

#define BUFF_SIZE 1024

class TinkerBoardServer
{
    typedef void *(*THREADFUNCPTR)(void *);

public:
    void Init();
    //void Send_message(std::vector<Message_From_Server>);
    // std::vector<Message_SendTo_Server> Get_message();
    // bool Has_message();
private:
    void thread_accept();
public:
    Signal<Message_SendTo_Server> sig_msg;
public:
    void slot_send_msg(Message_From_Server);
private:
    int conn_;

    // std::mutex mutex_msg_send_;
    // std::vector<Message_From_Server> msgs_send_;

    // std::mutex mutex_msg_receive_;
    // std::vector<Message_SendTo_Server> msgs_receive_;
};

#endif