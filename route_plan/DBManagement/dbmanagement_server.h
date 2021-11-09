#include <thread>
#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <vector>
#include <mutex>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "dbmanagement_ordermanagement.grpc.pb.h"
#include "dbmanagement_common.h"
#include "mongodbmanager.h"

#ifndef DBMANAGEMENT_SERVER
#define DBMANAGEMENT_SERVER

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

using grpc_dbmanagement::DBManagement_OrderManagement_Service;
using grpc_dbmanagement::Reply_Insert;
using grpc_dbmanagement::Request_Insert;
using grpc_dbmanagement::Request_Insert_Goods_Info;
using grpc_dbmanagement::Request_Insert_Order_Data;

// class DBManagement_GRPC_Server
// {
// public:
//     enum DBMANAGEMENT_GRPC_SERVER_MESSAGETYPE
//     {
//         DBMANAGEMENT_GRPC_SERVER_MESSAGETYPE_DEFAULT = 0,
//         DBMANAGEMENT_GRPC_SERVER_MESSAGETYPE_INSERT_ORDER = 1,
//     };
//     template <typename T>
//     struct DBManagement_GRPC_Server_Message
//     {
//         DBMANAGEMENT_GRPC_SERVER_MESSAGETYPE type = DBMANAGEMENT_GRPC_SERVER_MESSAGETYPE_DEFAULT;
//         T data;
//     };

// public:
//     ~DBManagement_GRPC_Server()
//     {
//         server_->Shutdown();
//         cq_->Shutdown();
//     }
//     void Init();
//     // bool HasMessage();
//     // std::vector<DBManagement_GRPC_Server_Message<Order>> GetMessage();
// private:
//     void HandleRpcs();

// public:
//     class CallData
//     {
//     private:
//         enum CallStatus
//         {
//             CREATE,
//             PROCESS,
//             FINISH
//         };

//     public:
//         CallData(DBManagement_OrderManagement_Service::AsyncService *service, ServerCompletionQueue *cq)
//             : dbm_orderm_service_(service), cq_(cq), responder_(&ctx_), status_(CREATE)
//         {
//             // Invoke the serving logic right away.
//             Proceed();
//         }

//         void Proceed()
//         {
//             std::cout << "server proceed \n";
//             if (status_ == CREATE)
//             {
//                 // Make this instance progress to the PROCESS state.
//                 status_ = PROCESS;

//                 // As part of the initial CREATE state, we *request* that the system
//                 // start processing SayHello requests. In this request, "this" acts are
//                 // the tag uniquely identifying the request (so that different CallData
//                 // instances can serve different requests concurrently), in this case
//                 // the memory address of this CallData instance.
//                 dbm_orderm_service_->RequestInsert(&ctx_, &request_insert_, &responder_, cq_, cq_, this);
//             }
//             else if (status_ == PROCESS)
//             {
//                 // Spawn a new CallData instance to serve new clients while we process
//                 // the one for this CallData. The instance will deallocate itself as
//                 // part of its FINISH state.
//                 new CallData(dbm_orderm_service_, cq_);

//                 // The actual processing.
//                 reply_insert_.set_insert_result(true);

//                 Order order;
//                 order.number = request_insert_.number();
//                 order.time = request_insert_.time();
//                 order.data.goods_info.name = request_insert_.unsafe_arena_release_data()->goods_info().name();
//                 order.data.goods_pos = request_insert_.unsafe_arena_release_data()->goods_pos();
//                 order.data.target_pos = request_insert_.unsafe_arena_release_data()->target_pos();
//                 order.type = request_insert_.type();
//                 order.result = request_insert_.result();

//                 MongodbManager::GetInstance()->Insert(order);
//                 std::cout << "server insert into db \n";

//                 // mutex_message_.lock();
//                 // message_.push_back(server_message);
//                 // mutex_message_.unlock();

//                 // And we are done! Let the gRPC runtime know we've finished, using the
//                 // memory address of this instance as the uniquely identifying tag for
//                 // the event.
//                 status_ = FINISH;
//                 responder_.Finish(reply_insert_, Status::OK, this);
//             }
//             else
//             {
//                 GPR_ASSERT(status_ == FINISH);
//                 // Once in the FINISH state, deallocate ourselves (CallData).
//                 delete this;
//             }
//         }

//     private:
//         DBManagement_OrderManagement_Service::AsyncService *dbm_orderm_service_;
//         ServerCompletionQueue *cq_;
//         ServerContext ctx_;

//         Request_Insert request_insert_;
//         Reply_Insert reply_insert_;
//         ServerAsyncResponseWriter<Reply_Insert> responder_;

//         CallStatus status_;
//     };

// private:
//     std::unique_ptr<ServerCompletionQueue> cq_;
//     DBManagement_OrderManagement_Service::AsyncService dbm_orderm_service_;
//     std::unique_ptr<Server> server_;

//     // std::vector<DBManagement_GRPC_Server_Message<Order>> message_;
//     // std::mutex mutex_message_;
// };

class DBManagement_OrderManagement_Service_Impl final : public DBManagement_OrderManagement_Service::Service
{
    Status Insert(ServerContext *context, const Request_Insert *request,
                  Reply_Insert *reply) override
    {
        Order order;
        order.number = request->number();
        order.time = request->time();
        order.data.goods_info.name = request->data().goods_info().name();
        order.data.goods_pos = request->data().goods_pos();
        order.data.target_pos = request->data().target_pos();
        order.type = request->type();
        order.result = request->result();

        std::cout << "server insert into db \n";
        MongodbManager::GetInstance()->Insert(order);
        reply->set_insert_result(true);
        return Status::OK;
    }
};

class DBManagement_OrderManagement_Server
{
public:
    void Init();

private:
    ServerBuilder *builder_;
    DBManagement_OrderManagement_Service_Impl *db_order_service_;
};
#endif