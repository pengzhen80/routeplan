// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: route_planner.proto
#ifndef GRPC_route_5fplanner_2eproto__INCLUDED
#define GRPC_route_5fplanner_2eproto__INCLUDED

#include "route_planner.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace route_planner {

class RoutePlanner final {
 public:
  static constexpr char const* service_full_name() {
    return "route_planner.RoutePlanner";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status SendRequest(::grpc::ClientContext* context, const ::route_planner::Request& request, ::route_planner::Reply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::Reply>> AsyncSendRequest(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::Reply>>(AsyncSendRequestRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::Reply>> PrepareAsyncSendRequest(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::Reply>>(PrepareAsyncSendRequestRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void SendRequest(::grpc::ClientContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void SendRequest(::grpc::ClientContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void SendRequest(::grpc::ClientContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::Reply>* AsyncSendRequestRaw(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::Reply>* PrepareAsyncSendRequestRaw(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status SendRequest(::grpc::ClientContext* context, const ::route_planner::Request& request, ::route_planner::Reply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::Reply>> AsyncSendRequest(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::Reply>>(AsyncSendRequestRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::Reply>> PrepareAsyncSendRequest(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::Reply>>(PrepareAsyncSendRequestRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void SendRequest(::grpc::ClientContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void SendRequest(::grpc::ClientContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void SendRequest(::grpc::ClientContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::route_planner::Reply>* AsyncSendRequestRaw(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::route_planner::Reply>* PrepareAsyncSendRequestRaw(::grpc::ClientContext* context, const ::route_planner::Request& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SendRequest_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status SendRequest(::grpc::ServerContext* context, const ::route_planner::Request* request, ::route_planner::Reply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendRequest() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRequest(::grpc::ServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendRequest(::grpc::ServerContext* context, ::route_planner::Request* request, ::grpc::ServerAsyncResponseWriter< ::route_planner::Reply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SendRequest<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_SendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_SendRequest() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::route_planner::Request, ::route_planner::Reply>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::route_planner::Request* request, ::route_planner::Reply* response) { return this->SendRequest(context, request, response); }));}
    void SetMessageAllocatorFor_SendRequest(
        ::grpc::experimental::MessageAllocator< ::route_planner::Request, ::route_planner::Reply>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::route_planner::Request, ::route_planner::Reply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_SendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRequest(::grpc::ServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SendRequest(
      ::grpc::CallbackServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SendRequest(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_SendRequest<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_SendRequest<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendRequest() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRequest(::grpc::ServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendRequest() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRequest(::grpc::ServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendRequest(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_SendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_SendRequest() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendRequest(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_SendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRequest(::grpc::ServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SendRequest(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SendRequest(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendRequest() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::route_planner::Request, ::route_planner::Reply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::route_planner::Request, ::route_planner::Reply>* streamer) {
                       return this->StreamedSendRequest(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendRequest(::grpc::ServerContext* /*context*/, const ::route_planner::Request* /*request*/, ::route_planner::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendRequest(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::route_planner::Request,::route_planner::Reply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SendRequest<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SendRequest<Service > StreamedService;
};

}  // namespace route_planner


#endif  // GRPC_route_5fplanner_2eproto__INCLUDED
