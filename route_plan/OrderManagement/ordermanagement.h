#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <mutex>
#include "ordermanagement_common.h"
#include "ordermanagement_client.h"
#include "TinkerBoardServer.h"
#include "Core/Core_Connect/core_connect.h"

#ifndef ORDERMANAGEMENT
#define ORDERMANAGEMENT
using namespace ordermangement_common;

using Core_Connect::Signal;
using Core_Connect::Slot;

class OrderManagement
{
protected:
    explicit OrderManagement()
    {
        // four sub thread
        dbclient_ = new DBManagementClient(grpc::CreateChannel(
            "localhost:50052", grpc::InsecureChannelCredentials()));
        std::thread thread_ = std::thread(&DBManagementClient::AsyncCompleteRpc, dbclient_);
        thread_.detach();

        jobclient_ = new JobManagementClient(grpc::CreateChannel(
            "localhost:50054", grpc::InsecureChannelCredentials()));
        std::thread t_jobclient_ = std::thread(&JobManagementClient::AsyncCompleteRpc, jobclient_);
        t_jobclient_.detach();

        server_tinkerboard = new TinkerBoardServer();
        std::thread t_server_tinkerboard(&TinkerBoardServer::Init, server_tinkerboard);
        t_server_tinkerboard.detach();

        std::thread t_thread_act_order(&OrderManagement::thread_act_order, this);
        t_thread_act_order.detach();

        event_connect(this,sig_send_msg ,std::bind(&TinkerBoardServer::slot_send_msg,server_tinkerboard,std::placeholders::_1));
        event_connect(server_tinkerboard,sig_msg ,std::bind(&OrderManagement::slot_receive_msg,this,std::placeholders::_1));
    }

public:
    static OrderManagement *GetInstance();

    int Add_Order(Order_For_OrderManagement order);
    bool Cancel_Order(int order_num); //need to update
    void Set_Order_State(int order_num, ORDERSTATE state);
    ~OrderManagement();

    //for jobmanagement
    bool HasOrder();
    std::vector<Order_For_JobManagement> GetOrder();
    //for DBmanagement
    bool HasData_ForDB();
    std::vector<Data_For_DB> GetData();

    bool insert_into_DB(Data_For_DB data);

public://for test
    void Test_Init_Cars(std::vector<int> init_cars);
    void Test_Init_Customers(std::vector<int> init_customers);
private://for test
    void test_set_car_unusable(int car_id);
    void test_set_car_usable(int car_id);
    //default func for test
    std::vector<int> default_ask_car_useful();
    std::vector<int> default_ask_customer_tags();
private:
    void thread_act_order();
public://send msg by server
    Signal<Message_From_Server> sig_send_msg;
public://get msg from server
    void slot_receive_msg(Message_SendTo_Server);

private:
    void push_into_orderlist(OrderManagement_Order order);
    void pop_from_orderlist(int order_num);
    bool check_order(int order_num);

    Order_For_JobManagement make_order_for_JobManagement(int order_num);
    Order_For_JobManagement make_order_for_JobManagement(OrderManagement_Order order);

private: //tool  functions
    int make_order_num();
    std::string make_order_time();
    int make_order_weight();


private:
    std::vector<OrderManagement_Order> orderlist_;
    std::unordered_map<int, int> order_num_index_;

    std::vector<Order_For_JobManagement> orderlist_jobmanagement_;
    std::mutex mutex_orderlist_jobmanagement_;

    std::vector<Data_For_DB> datalist_db_;
    int order_count_ = 0;

private://server of tinkerboard
     TinkerBoardServer * server_tinkerboard;
private://singalton pattern
    static OrderManagement *instance_;
    static std::mutex mutex_instance_;

    DBManagementClient *dbclient_;
    JobManagementClient* jobclient_;
private: // for test
    std::vector<int> test_cars_;
    std::vector<int> test_customers_;
};

#endif
