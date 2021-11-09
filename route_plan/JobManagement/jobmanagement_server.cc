#include "jobmanagement_server.h"


void JobManagement_Server::Init()
{
    job_order_service_ = new JobManagement_OrderManagement_Service_Impl();

    std::string server_address("0.0.0.0:50054");
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    builder_ = new ServerBuilder();
    builder_->AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder_->RegisterService(job_order_service_);
    std::unique_ptr<Server> server(builder_->BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
    //while(true);
}