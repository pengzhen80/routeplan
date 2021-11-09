#include "dbmanagement_server.h"

// void DBManagement_GRPC_Server::Init()
// {
//     std::string server_address("0.0.0.0:50051");

//     ServerBuilder builder;
//     // Listen on the given address without any authentication mechanism.
//     builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
//     // Register "service_" as the instance through which we'll communicate with
//     // clients. In this case it corresponds to an *asynchronous* service.
//     builder.RegisterService(&dbm_orderm_service_);
//     // Get hold of the completion queue used for the asynchronous communication
//     // with the gRPC runtime.
//     cq_ = builder.AddCompletionQueue();
//     // Finally assemble the server.
//     server_ = builder.BuildAndStart();
//     std::cout << "Server listening on " << server_address << std::endl;

//     std::thread t_receive(&DBManagement_GRPC_Server::HandleRpcs, this);
//     t_receive.detach();
// }

// void DBManagement_GRPC_Server::HandleRpcs()
// {
//     // Spawn a new CallData instance to serve new clients.
//     new CallData(&dbm_orderm_service_, cq_.get());
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
//         static_cast<CallData *>(tag)->Proceed();
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

void DBManagement_OrderManagement_Server::Init()
{
    db_order_service_ = new DBManagement_OrderManagement_Service_Impl();

    std::string server_address("0.0.0.0:50052");
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    builder_ = new ServerBuilder();
    builder_->AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder_->RegisterService(db_order_service_);
    std::unique_ptr<Server> server(builder_->BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
    //while(true);
}
