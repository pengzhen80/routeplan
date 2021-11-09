#include <iostream>
#include <memory>
#include <string>

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <thread>
#include <mutex>

#include "ordermanagement_common.h"
#include "grpc_files/grpc_dbmanagement_files/dbmanagement_ordermanagement.grpc.pb.h"
#include "grpc_files/grpc_jobmanagement_files/jobmanagement_ordermanagement.grpc.pb.h"

#ifndef DBMANAGEMENTCLIENT
#define DBMANAGEMENTCLIENT

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using grpc_dbmanagement::DBManagement_OrderManagement_Service;
using grpc_dbmanagement::Reply_Insert;
using grpc_dbmanagement::Request_Insert;
using grpc_dbmanagement::Request_Insert_Goods_Info;
using grpc_dbmanagement::Request_Insert_Order_Data;

using grpc_jobmanagement::JobManagement_OrderManagement_Service;
using grpc_jobmanagement::Reply_Act;
using grpc_jobmanagement::Reply_Cancel;
using grpc_jobmanagement::Request_Order;

using namespace ordermangement_common;

class DBManagementClient
{
public:
  explicit DBManagementClient(std::shared_ptr<Channel> channel)
      : stub_(DBManagement_OrderManagement_Service::NewStub(channel))
  {
    std::thread t_client = std::thread(&DBManagementClient::AsyncCompleteRpc, this);
    t_client.detach();
  }

public:
  //static DBManagementClient *GetInstance();
  void Insert_Data(const Data_For_DB &data);
  void AsyncCompleteRpc();

private:
  struct AsyncClientCall
  {
    Reply_Insert reply;
    ClientContext context;
    Status status;
    std::unique_ptr<ClientAsyncResponseReader<Reply_Insert>> response_reader;
  };
  std::unique_ptr<DBManagement_OrderManagement_Service::Stub> stub_;
  CompletionQueue cq_;
};


class JobManagementClient
{
public:
  explicit JobManagementClient(std::shared_ptr<Channel> channel)
      : stub_(JobManagement_OrderManagement_Service::NewStub(channel))
  {
    std::thread t_client = std::thread(&JobManagementClient::AsyncCompleteRpc, this);
    t_client.detach();
  }

public:
  void Act_Order(const Order_For_JobManagement &data);
  void Cancel_Order(const Order_For_JobManagement &data);//todo
  void AsyncCompleteRpc();

private:
  enum RPC_TYPE
  {
    RPC_TYPE_ACT_ORDER = 0,
    RPC_TYPE_CANCEL_ORDER,
  };
  struct AsyncClientCall
  {
    Reply_Act reply_act;
    Reply_Cancel reply_cancel;
    ClientContext context;
    Status status;
    std::unique_ptr<ClientAsyncResponseReader<Reply_Act>> response_reader_act;
    std::unique_ptr<ClientAsyncResponseReader<Reply_Cancel>> response_reader_reply;
    RPC_TYPE type;
  };
  std::unique_ptr<JobManagement_OrderManagement_Service::Stub> stub_;
  CompletionQueue cq_;
};

#endif