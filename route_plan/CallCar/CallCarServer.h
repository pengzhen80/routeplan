#include <string.h>
#include "Protocol/CarDrivingNodeSharedProtocol/CarDrivingSharedProtocol.h"
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

#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)
#define CAR_DRIVING_SERVER_NETWORK_MESSAGE_VERSION 20210106
//2978 5978
#define CAR_DRIVING_SERVER_NETWORK_TARGET_PORT 2978
#define BUFF_SIZE 1024

//at the first time,the message struct sended from server to car
#pragma pack(push, 1)
struct SendBuf
{
    int lenth;
    struct sNetwork_eCDNM_S2C_TELL_SERVER_WHO_YOU_ARE_REQUEST message;
};
#pragma pack(pop)

//message send to car for run from A to B
#pragma pack(push, 1)
struct SendCarGo
{
    int lenth;
    struct sNetwork_eCDNM_S2C_CAR_GO_TO_DESTINATION_REQUEST message;
};
#pragma pack(pop)

#define SIMULATOR_ROUTESIZE 10
#define INITCARSIZE 1000
enum SIMULATOR_MSGTYPE
{
    SIMULATOR_MSGTYPE_INIT_CAR = 0,
    SIMULATOR_MSGTYPE_ASKPATH = 1,
};

struct SendCarGo_Simulator
{
    int size;
    int route[SIMULATOR_ROUTESIZE];
};
struct Simulator_SidEid
{
    int msgtype;
    int car_id;
    int s_id;
    int e_id;
};

struct Simulator_InitCar
{
    int msg_type;
    int car_num;
    int car_id_pos[INITCARSIZE];
};

#pragma pack(push, 1)
struct ReceiveBuf
{
    int lenth;
    struct sNetwork_eCDNM_C2S_CAR_STATUS message;
};
#pragma pack(pop)

class CallCarServer
{
    typedef void *(*THREADFUNCPTR)(void *);

public:
    void Init();
    //void send_message(std::vector<int> vec_route, float distance);
    void send_message(std::vector<int> vec_route);
    std::vector<std::vector<int>> get_message();
    bool has_message();

private:
    struct SendCarGo* MakeSendBufByRoute(std::vector<int> vec_route, float distance);
    //void* thread_accept(void *data);
    void thread_accept();
    //void DealQueue();

private:
    //static CallCarServer* instance_; //need to do
    std::queue<struct SendCarGo*> que_send_;
    std::mutex que_send_mutex_;
    std::queue<struct ReceiveBuf *> que_receive_;
    std::mutex que_receive_mutex_;
    int conn_= -1;
    bool b_receive_ = true;
    bool b_send_ = true;
    SendCarGo m_cargo_;

    std::mutex m_mutex_simulator;
    SendCarGo_Simulator m_cargo_simulator_;

    std::mutex m_mutex_simulator_receive_;
    std::vector<int> m_simulator_receive_;
    //receive que
    std::mutex m_mutex_simulator_que_receive_;
    std::queue<std::vector<int>> m_simulator_que_receive_;
};
