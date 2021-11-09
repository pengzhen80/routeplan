#include <thread>
#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>
#include <vector>
#include <mutex>

#include "ordermanagement_jobmanagement.grpc.pb.h"
#include "ordermanagement_ordersystem.grpc.pb.h"
#include "ordermanagement_common.h"
#include "ordermanagement.h"

#ifndef ORDERMANAGEMENT_SERVER
#define ORDERMANAGEMENT_SERVER

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

using grpc_ordermanagement::OrderManagement_JobManagement_Service;
using grpc_ordermanagement::Reply_SetOrderState;
using grpc_ordermanagement::Request_SetOrderState;
using grpc_ordermanagement::Request_SetOrderState_TYPE;

using grpc_ordermanagement::OrderManagement_OrderSystem_Service;
using grpc_ordermanagement::Reply_AddOrder;
using grpc_ordermanagement::Reply_CancelOrder;
using grpc_ordermanagement::Reply_CancelOrder_TYPE;
using grpc_ordermanagement::Request_AddOrder;
using grpc_ordermanagement::Request_AddOrder_TYPE;
using grpc_ordermanagement::Request_CancelOrder;
using grpc_ordermanagement::Request_CancelOrder_TYPE;

// class OrderManagement_GRPC_Server
// {
// public:
//     enum ORDERMANAGEMENT_GRPC_SERVICE_TYPE
//     {
//         ORDERMANAGEMENT_GRPC_SERVICE_TYPE_JOBMANAGEMENT = 0,
//         ORDERMANAGEMENT_GRPC_SERVICE_TYPE_ORDERSYSTEM,
//     };
//     ~OrderManagement_GRPC_Server()
//     {
//         server_->Shutdown();
//         cq_->Shutdown();
//     }
//     void Init();

// private:
//     void HandleRpcs();

// private:
//     std::unique_ptr<ServerCompletionQueue> cq_;
//     OrderManagement_JobManagement_Service::AsyncService order_job_service_;
//     OrderManagement_OrderSystem_Service::AsyncService order_ordersys_service_;
//     std::unique_ptr<Server> server_;
// };

// class OrderSystem_CallData
// {
// protected:
//     enum CallStatus
//     {
//         CREATE,
//         PROCESS,
//         FINISH
//     };

// public:
//     OrderSystem_CallData(OrderManagement_OrderSystem_Service::AsyncService *service, ServerCompletionQueue *cq)
//     {
//         Proceed();
//     }
//     virtual void Proceed();
// };

// class OrderSystem_AddOrder_CallData final : public OrderSystem_CallData
// {
// public:
//     OrderSystem_AddOrder_CallData(OrderManagement_OrderSystem_Service::AsyncService *service, ServerCompletionQueue *cq)
//         : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE)
//     {
//         Proceed();
//     }

//     void Proceed() override;

// private:
//     OrderManagement_OrderSystem_Service::AsyncService *service_;
//     ServerCompletionQueue *cq_;
//     ServerContext ctx_;

//     Request_AddOrder request_addorder_;
//     Reply_AddOrder reply_addorder_;
//     ServerAsyncResponseWriter<Reply_AddOrder> responder_;

//     CallStatus status_;
// };

// class OrderSystem_CancelOrder_CallData final : public OrderSystem_CallData
// {
// public:
//     OrderSystem_CancelOrder_CallData(OrderManagement_OrderSystem_Service::AsyncService *service, ServerCompletionQueue *cq)
//         : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE)
//     {
//         Proceed();
//     }

//     void Proceed() override;

// private:
//     OrderManagement_OrderSystem_Service::AsyncService *service_;
//     ServerCompletionQueue *cq_;
//     ServerContext ctx_;

//     Request_CancelOrder request_cancelorder_;
//     Reply_CancelOrder reply_cancelorder_;
//     ServerAsyncResponseWriter<Reply_CancelOrder> responder_;

//     CallStatus status_;
// };

class OrderManagement_JobManagement_Service_Impl final : public OrderManagement_JobManagement_Service::Service
{
    Status SetOrderState(ServerContext *context, const Request_SetOrderState *request,
                         Reply_SetOrderState *reply) override
    {

        int order_number = request->number();
        ORDERSTATE order_state;
        Request_SetOrderState_TYPE state_type = request->type();
        switch (state_type)
        {
        case Request_SetOrderState_TYPE::Request_SetOrderState_TYPE_FINISH:
        {
            order_state = ORDERSTATE::ORDERSTATE_FINISH;
        }
        break;
        case Request_SetOrderState_TYPE::Request_SetOrderState_TYPE_CANCEL:
        {
            order_state = ORDERSTATE::ORDERSTATE_CANCEL;
        }
        break;
        default:
            break;
        }
        std::cout << "ordermanagement service: set state into ordermanagement \n";
        reply->set_reply_set(true);
        OrderManagement::GetInstance()->Set_Order_State(order_number, order_state);   
        return Status::OK;
    }
};

class OrderManagement_OrderSystem_Service_Impl final : public OrderManagement_OrderSystem_Service::Service
{
    Status AddOrder(ServerContext *context, const Request_AddOrder *request,
                         Reply_AddOrder *reply) override
    {
        Order_For_OrderManagement order;
        order.goods_pos = request->data().goods_pos();
        order.target_pos = request->data().target_pos();
        order.info.name = request->data().goods_info().name(); 
        order.act = ORDERACTION::ORDERACTION_ACT;

        Request_AddOrder_TYPE type = request->type();
        switch (type)
        {
        case Request_AddOrder_TYPE::Request_AddOrder_TYPE_MEAL_DELIVERY:
        {
            order.type = ORDERTYPE::ORDERTYPE_RESTAURANT_DELEVER;
        }
        break;
        case Request_AddOrder_TYPE::Request_AddOrder_TYPE_MEAL_RECEPTION:
        {
            order.type = ORDERTYPE::ORDERTYPE_RESTAURANT_RECYCLE;
        }
        break;
        default:
            break;
        }

        std::cout << "ordermanagement service: add order into ordermanagement \n";
        int order_number = OrderManagement::GetInstance()->Add_Order(order);
        reply->set_order_number(order_number);
        return Status::OK;
    }

     Status CancelOrder(ServerContext *context, const Request_CancelOrder *request,
                         Reply_CancelOrder *reply) override
    {
        int order_number = request->order_number();
        //Request_CancelOrder_TYPE type = request->type();

        std::cout << "ordermanagement service: add order into ordermanagement \n";
        bool cancel_flag = OrderManagement::GetInstance()->Cancel_Order(order_number);
        if(cancel_flag)
        {
            reply->set_reply_cancel(Reply_CancelOrder_TYPE::Reply_CancelOrder_TYPE_SUCCESS);
        }
        else
        {
            reply->set_reply_cancel(Reply_CancelOrder_TYPE::Reply_CancelOrder_TYPE_FAIL);
        }
        return Status::OK;
    }
};

class OrderManagement_Server
{
public:
    void Init();
private:
    ServerBuilder *builder_;
    OrderManagement_JobManagement_Service_Impl *order_job_service_;
    OrderManagement_OrderSystem_Service_Impl* order_ordersys_service_;
};

#endif