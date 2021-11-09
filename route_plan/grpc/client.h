// #include <grpc/grpc.h>
// #include <grpcpp/channel.h>
// #include <grpcpp/client_context.h>
// #include <grpcpp/create_channel.h>
// #include <thread>
// #include "route_planner.grpc.pb.h"

// using grpc::Channel;
// using grpc::ClientAsyncResponseReader;
// using grpc::ClientContext;
// using grpc::CompletionQueue;
// using grpc::ClientReader;
// using grpc::ClientReaderWriter;
// using grpc::ClientWriter;
// using grpc::Status;
// using route_planner::Request;
// using route_planner::Reply;
// using route_planner::RoutePlanner;

// class RpClient{
// public:
//   RpClient(std::shared_ptr<Channel> channel)
//     :stub_(RoutePlanner::NewStub(channel)){}

//     void SendRequest(int s_id, int e_id); //parameters are better to use a struct
//     void AsyncCompleteRpc();
//   private:
//     struct AsyncClientCall
//     {
//       Reply reply;
//       ClientContext context;
//       Status status;
//       std::unique_ptr<ClientAsyncResponseReader<Reply>> response_reader;
//     };
//     std::unique_ptr<RoutePlanner::Stub> stub_;
//     CompletionQueue cq_;
// };
