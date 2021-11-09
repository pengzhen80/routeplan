#include "ordermanagement_client.h"

// DBManagementClient *DBManagementClient::instance_ = nullptr;
// std::mutex DBManagementClient::mutex_instance_;

// DBManagementClient *DBManagementClient::GetInstance()
// {
//   std::lock_guard<std::mutex> lock(mutex_instance_);
//   if (nullptr == instance_)
//   {
//     instance_ = new DBManagementClient(grpc::CreateChannel(
//         "0.0.0.0:50051", grpc::InsecureChannelCredentials()));
//   }
//   return instance_;
// }

void DBManagementClient::Insert_Data(const Data_For_DB &data)
{
  Request_Insert request;
  request.set_number(data.number);
  request.set_result(data.result);
  request.set_time(data.time);
  request.set_type(data.type);
  request.mutable_data()->set_goods_pos(data.data.goods_pos);
  request.mutable_data()->set_target_pos(data.data.target_pos);
  request.mutable_data()->mutable_goods_info()->set_name(data.data.goods_info.name);
  std::cout << "clinet ask service : insert \n";

  // Call object to store rpc data
  AsyncClientCall *call = new AsyncClientCall;
  call->response_reader =
      stub_->PrepareAsyncInsert(&call->context, request, &cq_);
  call->response_reader->StartCall();
  call->response_reader->Finish(&call->reply, &call->status, (void *)call);
}

void DBManagementClient::AsyncCompleteRpc()
{
  void *got_tag;
  bool ok = false;
  while (cq_.Next(&got_tag, &ok))
  {
    AsyncClientCall *call = static_cast<AsyncClientCall *>(got_tag);
    GPR_ASSERT(ok);
    if (call->status.ok())
    {
      std::cout << "Insert DB received: " << call->reply.insert_result() << std::endl;
    }
    else
      std::cout << "Insert DB RPC failed" << std::endl;
    delete call;
  }
}

void JobManagementClient::Act_Order(const Order_For_JobManagement &data)
{
  Request_Order request;
  request.set_number(data.number);
  request.set_car_id(data.data.car_id);
  //request.set_type();
  request.mutable_data()->set_goods_pos(data.data.goods_pos);
  request.mutable_data()->set_target_pos(data.data.target_pos);
  request.mutable_data()->mutable_goods_info()->set_name(data.data.goods_info.name);
  std::cout << "JobManagementClient ask service : act order "<<data.data.car_id<<"\n";

  // Call object to store rpc data
  AsyncClientCall *call = new AsyncClientCall;
  call->response_reader_act =
      stub_->PrepareAsyncActOrder(&call->context, request, &cq_);
  call->response_reader_act->StartCall();
  call->response_reader_act->Finish(&call->reply_act, &call->status, (void *)call);
  call->type = RPC_TYPE_ACT_ORDER;
}

void JobManagementClient::AsyncCompleteRpc()
{
  void *got_tag;
  bool ok = false;
  while (cq_.Next(&got_tag, &ok))
  {
    AsyncClientCall *call = static_cast<AsyncClientCall *>(got_tag);
    GPR_ASSERT(ok);
    if (call->status.ok())
    {
      switch (call->type)
      {
      case RPC_TYPE::RPC_TYPE_ACT_ORDER:
        std::cout << "act order received: " << call->reply_act.reply_act() << std::endl;
        break;
      default:
        break;
      }
      //std::cout << "act order received: " << call->reply_act.reply_act() << std::endl;
    }
    else
      std::cout << "Insert DB RPC failed" << std::endl;
    delete call;
  }
}