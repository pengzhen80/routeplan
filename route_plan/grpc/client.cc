// #include "client.h"

// void  RpClient::SendRequest(int s_id,int e_id)
// {
//     Request request;
//     request.set_start_id(s_id);
//     request.set_end_id(e_id);
//     AsyncClientCall* call = new AsyncClientCall;
//     call->response_reader = stub_->PrepareAsyncSendRequest(&call->context,request,&cq_);
//     call->response_reader->StartCall();
//     call->response_reader->Finish(&call->reply,&call->status,(void*)call);
// }
// void RpClient::AsyncCompleteRpc()
// {
//   std::cout<<std::this_thread::get_id()<<std::endl;
//   void* got_tag;
//   bool ok = false;

//   while(cq_.Next(&got_tag,&ok))
//   {
//     AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);
//     GPR_ASSERT(ok);

//     if(call->status.ok()){
//       std::cout<<"received"<<std::endl;
//     }
//     else
//     {
//       std::cout<<"rpc failed" <<std::endl;
//     }
//     delete call;
//   }
// }
