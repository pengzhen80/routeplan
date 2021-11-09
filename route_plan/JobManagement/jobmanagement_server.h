#include <thread>
#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>
#include <vector>
#include <mutex>

#include "grpc_files/jobmanagement_ordermanagement/jobmanagement_ordermanagement.grpc.pb.h"
#include "jobmanagement_common.h"
#include "jobmanagement.h"

#ifndef JOBMANAGEMENT_SERVER
#define JOBMANAGEMENT_SERVER

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

using grpc_jobmanagement::JobManagement_OrderManagement_Service;
using grpc_jobmanagement::Reply_Act;
using grpc_jobmanagement::Reply_Cancel;
using grpc_jobmanagement::Request_Order;

class JobManagement_OrderManagement_Service_Impl final : public JobManagement_OrderManagement_Service::Service
{
    Status ActOrder(ServerContext *context, const Request_Order *request,
                    Reply_Act *reply) override
    {
        JobMangement_Common::Order_For_JobManagement order;
        order.action = JobMangement_Common::ORDERACTION_ACT;
        order.data.car_id = request->car_id();
        order.data.target_pos = request->data().target_pos();

        std::cout << "jobmanagement service: act order into jobmanagement :"<< order.data.car_id << "\n";

        JobManagement::JobManagement::Instance()->Act_Order(order);
        return Status::OK;
    }

    Status CancelOrder(ServerContext *context, const Request_Order *request,
                       Reply_Cancel *reply) override
    {
        // int order_number = request->order_number();
        // //Request_CancelOrder_TYPE type = request->type();

        // std::cout << "ordermanagement service: add order into ordermanagement \n";
        // bool cancel_flag = OrderManagement::GetInstance()->Cancel_Order(order_number);
        // if (cancel_flag)
        // {
        //     reply->set_reply_cancel(Reply_CancelOrder_TYPE::Reply_CancelOrder_TYPE_SUCCESS);
        // }
        // else
        // {
        //     reply->set_reply_cancel(Reply_CancelOrder_TYPE::Reply_CancelOrder_TYPE_FAIL);
        // }
        return Status::OK;
    }
};

class JobManagement_Server
{
public:
    void Init();

private:
    ServerBuilder *builder_;
    JobManagement_OrderManagement_Service_Impl *job_order_service_;
};

#endif