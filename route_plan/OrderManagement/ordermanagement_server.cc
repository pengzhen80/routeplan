#include "ordermanagement_server.h"

// void OrderManagement_GRPC_Server::Init()
// {
//     std::string server_address("0.0.0.0:50051");

//     ServerBuilder builder;
//     // Listen on the given address without any authentication mechanism.
//     builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
//     // Register "service_" as the instance through which we'll communicate with
//     // clients. In this case it corresponds to an *asynchronous* service.
//     builder.RegisterService(&order_job_service_);
//     builder.RegisterService(&order_ordersys_service_);
//     // Get hold of the completion queue used for the asynchronous communication
//     // with the gRPC runtime.
//     cq_ = builder.AddCompletionQueue();
//     // Finally assemble the server.
//     server_ = builder.BuildAndStart();
//     std::cout << "Server listening on " << server_address << std::endl;

//     std::thread t_receive(&OrderManagement_GRPC_Server::HandleRpcs, this);
//     t_receive.detach();
// }

// void OrderManagement_GRPC_Server::HandleRpcs()
// {
//     // Spawn a new CallData instance to serve new clients.
//     // new OrderSystem_AddOrder_CallData(&order_ordersys_service_, cq_.get());
//     // new OrderSystem_CancelOrder_CallData(&order_ordersys_service_, cq_.get());
    
//     void *tag; // uniquely identifies a request.
//     bool ok;
//     while (true)
//     {
//         // Block waiting to read the next event from the completion queue. The
//         // event is uniquely identified by its tag, which in this case is the
//         // memory address of a CallData instance.
//         // The return value of Next should always be checked. This return value
//         // tells us whether there is any kind of event or cq_ is shutting down.
//         GPR_ASSERT(cq_->Next(&tag, &ok));
//         GPR_ASSERT(ok);
//         static_cast<OrderSystem_CallData *>(tag)->Proceed();
//     }
// }

// bool DBManagement_GRPC_Server::HasMessage()
// {
//     return !message_.empty();
// }

// std::vector<DBManagement_GRPC_Server::DBManagement_GRPC_Server_Message<Order>> DBManagement_GRPC_Server::GetMessage()
// {
//     std::vector<DBManagement_GRPC_Server_Message<Order>> result;
//     mutex_message_.lock();
//     result = message_;
//     mutex_message_.unlock();

//     return result;
// }

// void CallData::Proceed()
// {
//     if (status_ == CREATE)
//     {
//         status_ = PROCESS;
//         service_->RequestInsert(&ctx_, &request_insert_, &responder_, cq_, cq_, this);
//     }
//     else if (status_ == PROCESS)
//     {
//         new CallData(dbm_orderm_service_, cq_);

//         // The actual processing.
//         reply_insert_.set_insert_result(true);

//         Order order;
//         order.number = request_insert_.number();
//         order.time = request_insert_.time();
//         order.data.goods_info.name = request_insert_.unsafe_arena_release_data()->goods_info().name();
//         order.data.goods_pos = request_insert_.unsafe_arena_release_data()->goods_pos();
//         order.data.target_pos = request_insert_.unsafe_arena_release_data()->target_pos();
//         order.type = request_insert_.type();
//         order.result = request_insert_.result();

//         // DBManagement_GRPC_Server_Message<Order> server_message;
//         // server_message.type = DBMANAGEMENT_GRPC_SERVER_MESSAGETYPE_INSERT_ORDER;
//         // server_message.data = order;

//         MongodbManager::GetInstance()->Insert(order);
//         // mutex_message_.lock();
//         // message_.push_back(server_message);
//         // mutex_message_.unlock();

//         // And we are done! Let the gRPC runtime know we've finished, using the
//         // memory address of this instance as the uniquely identifying tag for
//         // the event.
//         status_ = FINISH;
//         responder_.Finish(reply_insert_, Status::OK, this);
//     }
//     else
//     {
//         GPR_ASSERT(status_ == FINISH);
//         // Once in the FINISH state, deallocate ourselves (CallData).
//         delete this;
//     }
// }

// void  OrderSystem_AddOrder_CallData::Proceed()
// {
//      if(status_ == CREATE)
//     {
//         status_ = PROCESS;
//         //service_->RequestInsert(&ctx_, &request_insert_, &responder_, cq_, cq_, this);
//         //service_->Request_AddOrder(&ctx_, &request_insert_, &responder_, cq_, cq_, this);
//         service_->RequestAddOrder(&ctx_, &request_addorder_, &responder_, cq_, cq_, this);
//     }
//     else if (status_ == PROCESS)
//     {
//         new OrderSystem_AddOrder_CallData(service_, cq_);

//         // The actual processing.
//         //generate number
        
//         //reply_addorder_.set_order_number(request_addorder_.)

//         Order_For_OrderManagement order;
//         order.goods_pos = request_addorder_.unsafe_arena_release_data()->goods_pos();
//         order.target_pos = request_addorder_.unsafe_arena_release_data()->target_pos();
//         order.type = (ORDERTYPE)request_addorder_.type();
//         order.act = ORDERACTION_ACT;
//         order.info.name = request_addorder_.unsafe_arena_release_data()->unsafe_arena_release_goods_info()->name();

//         //add into ordermangement and get a number to reply
//         int order_number = OrderManagement::GetInstance()->Add_Order(order);
//         reply_addorder_.set_order_number(order_number);

//         // And we are done! Let the gRPC runtime know we've finished, using the
//         // memory address of this instance as the uniquely identifying tag for
//         // the event.
//         status_ = FINISH;
//         responder_.Finish(reply_addorder_, Status::OK, this);
//     }
//     else
//     {
//         GPR_ASSERT(status_ == FINISH);
//         // Once in the FINISH state, deallocate ourselves (CallData).
//         delete this;
//     }
// }

// void  OrderSystem_CancelOrder_CallData::Proceed()
// {
//      if(status_ == CREATE)
//     {
//         status_ = PROCESS;
//         service_->RequestCancelOrder(&ctx_, &request_cancelorder_, &responder_, cq_, cq_, this);
//     }
//     else if (status_ == PROCESS)
//     {
//         new OrderSystem_CancelOrder_CallData(service_, cq_);

//         // The actual processing.
//         //cancel order and reply result

//         int order_number = request_cancelorder_.order_number();
//         bool cancel_result = OrderManagement::GetInstance()->Cancel_Order(order_number);

//         //add into ordermangement and get a number to reply
//         if(cancel_result)
//         {
//             reply_cancelorder_.set_reply_cancel(Reply_CancelOrder_TYPE::Reply_CancelOrder_TYPE_SUCCESS);
//         }
//         else{
//             reply_cancelorder_.set_reply_cancel(Reply_CancelOrder_TYPE::Reply_CancelOrder_TYPE_FAIL);
//         }
        

//         // And we are done! Let the gRPC runtime know we've finished, using the
//         // memory address of this instance as the uniquely identifying tag for
//         // the event.
//         status_ = FINISH;
//         responder_.Finish(reply_cancelorder_, Status::OK, this);
//     }
//     else
//     {
//         GPR_ASSERT(status_ == FINISH);
//         // Once in the FINISH state, deallocate ourselves (CallData).
//         delete this;
//     }
// }

void OrderManagement_Server::Init()
{
    order_job_service_ = new OrderManagement_JobManagement_Service_Impl();
    order_ordersys_service_ = new OrderManagement_OrderSystem_Service_Impl();

    std::string server_address("0.0.0.0:50053");
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    builder_ = new ServerBuilder();
    builder_->AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder_->RegisterService(order_job_service_);
    builder_->RegisterService(order_ordersys_service_);
    std::unique_ptr<Server> server(builder_->BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
    //while(true);
}