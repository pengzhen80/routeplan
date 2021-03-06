// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: ordermanagement_ordersystem.proto

#include "ordermanagement_ordersystem.pb.h"
#include "ordermanagement_ordersystem.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace grpc_ordermanagement {

static const char* OrderManagement_OrderSystem_Service_method_names[] = {
  "/grpc_ordermanagement.OrderManagement_OrderSystem_Service/AddOrder",
  "/grpc_ordermanagement.OrderManagement_OrderSystem_Service/CancelOrder",
};

std::unique_ptr< OrderManagement_OrderSystem_Service::Stub> OrderManagement_OrderSystem_Service::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OrderManagement_OrderSystem_Service::Stub> stub(new OrderManagement_OrderSystem_Service::Stub(channel));
  return stub;
}

OrderManagement_OrderSystem_Service::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_AddOrder_(OrderManagement_OrderSystem_Service_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CancelOrder_(OrderManagement_OrderSystem_Service_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OrderManagement_OrderSystem_Service::Stub::AddOrder(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_AddOrder& request, ::grpc_ordermanagement::Reply_AddOrder* response) {
  return ::grpc::internal::BlockingUnaryCall< ::grpc_ordermanagement::Request_AddOrder, ::grpc_ordermanagement::Reply_AddOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AddOrder_, context, request, response);
}

void OrderManagement_OrderSystem_Service::Stub::experimental_async::AddOrder(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_AddOrder* request, ::grpc_ordermanagement::Reply_AddOrder* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::grpc_ordermanagement::Request_AddOrder, ::grpc_ordermanagement::Reply_AddOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddOrder_, context, request, response, std::move(f));
}

void OrderManagement_OrderSystem_Service::Stub::experimental_async::AddOrder(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_AddOrder* request, ::grpc_ordermanagement::Reply_AddOrder* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AddOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_ordermanagement::Reply_AddOrder>* OrderManagement_OrderSystem_Service::Stub::PrepareAsyncAddOrderRaw(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_AddOrder& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::grpc_ordermanagement::Reply_AddOrder, ::grpc_ordermanagement::Request_AddOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AddOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::grpc_ordermanagement::Reply_AddOrder>* OrderManagement_OrderSystem_Service::Stub::AsyncAddOrderRaw(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_AddOrder& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OrderManagement_OrderSystem_Service::Stub::CancelOrder(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_CancelOrder& request, ::grpc_ordermanagement::Reply_CancelOrder* response) {
  return ::grpc::internal::BlockingUnaryCall< ::grpc_ordermanagement::Request_CancelOrder, ::grpc_ordermanagement::Reply_CancelOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CancelOrder_, context, request, response);
}

void OrderManagement_OrderSystem_Service::Stub::experimental_async::CancelOrder(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_CancelOrder* request, ::grpc_ordermanagement::Reply_CancelOrder* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::grpc_ordermanagement::Request_CancelOrder, ::grpc_ordermanagement::Reply_CancelOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CancelOrder_, context, request, response, std::move(f));
}

void OrderManagement_OrderSystem_Service::Stub::experimental_async::CancelOrder(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_CancelOrder* request, ::grpc_ordermanagement::Reply_CancelOrder* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CancelOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_ordermanagement::Reply_CancelOrder>* OrderManagement_OrderSystem_Service::Stub::PrepareAsyncCancelOrderRaw(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_CancelOrder& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::grpc_ordermanagement::Reply_CancelOrder, ::grpc_ordermanagement::Request_CancelOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CancelOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::grpc_ordermanagement::Reply_CancelOrder>* OrderManagement_OrderSystem_Service::Stub::AsyncCancelOrderRaw(::grpc::ClientContext* context, const ::grpc_ordermanagement::Request_CancelOrder& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCancelOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

OrderManagement_OrderSystem_Service::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_OrderSystem_Service_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrderManagement_OrderSystem_Service::Service, ::grpc_ordermanagement::Request_AddOrder, ::grpc_ordermanagement::Reply_AddOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrderManagement_OrderSystem_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::grpc_ordermanagement::Request_AddOrder* req,
             ::grpc_ordermanagement::Reply_AddOrder* resp) {
               return service->AddOrder(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderManagement_OrderSystem_Service_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrderManagement_OrderSystem_Service::Service, ::grpc_ordermanagement::Request_CancelOrder, ::grpc_ordermanagement::Reply_CancelOrder, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrderManagement_OrderSystem_Service::Service* service,
             ::grpc::ServerContext* ctx,
             const ::grpc_ordermanagement::Request_CancelOrder* req,
             ::grpc_ordermanagement::Reply_CancelOrder* resp) {
               return service->CancelOrder(ctx, req, resp);
             }, this)));
}

OrderManagement_OrderSystem_Service::Service::~Service() {
}

::grpc::Status OrderManagement_OrderSystem_Service::Service::AddOrder(::grpc::ServerContext* context, const ::grpc_ordermanagement::Request_AddOrder* request, ::grpc_ordermanagement::Reply_AddOrder* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrderManagement_OrderSystem_Service::Service::CancelOrder(::grpc::ServerContext* context, const ::grpc_ordermanagement::Request_CancelOrder* request, ::grpc_ordermanagement::Reply_CancelOrder* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace grpc_ordermanagement

