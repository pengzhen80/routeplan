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
    virtual ::grpc::Status SendRoute(::grpc::ClientContext* context, const ::route_planner::request& request, ::route_planner::route* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::route>> AsyncSendRoute(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::route>>(AsyncSendRouteRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::route>> PrepareAsyncSendRoute(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::route>>(PrepareAsyncSendRouteRaw(context, request, cq));
    }
    virtual ::grpc::Status SendOrder(::grpc::ClientContext* context, const ::route_planner::route& request, ::route_planner::car_order* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::car_order>> AsyncSendOrder(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::car_order>>(AsyncSendOrderRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::car_order>> PrepareAsyncSendOrder(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::car_order>>(PrepareAsyncSendOrderRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void SendRoute(::grpc::ClientContext* context, const ::route_planner::request* request, ::route_planner::route* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void SendRoute(::grpc::ClientContext* context, const ::route_planner::request* request, ::route_planner::route* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void SendRoute(::grpc::ClientContext* context, const ::route_planner::request* request, ::route_planner::route* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      virtual void SendOrder(::grpc::ClientContext* context, const ::route_planner::route* request, ::route_planner::car_order* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void SendOrder(::grpc::ClientContext* context, const ::route_planner::route* request, ::route_planner::car_order* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void SendOrder(::grpc::ClientContext* context, const ::route_planner::route* request, ::route_planner::car_order* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
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
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::route>* AsyncSendRouteRaw(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::route>* PrepareAsyncSendRouteRaw(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::car_order>* AsyncSendOrderRaw(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::route_planner::car_order>* PrepareAsyncSendOrderRaw(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status SendRoute(::grpc::ClientContext* context, const ::route_planner::request& request, ::route_planner::route* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::route>> AsyncSendRoute(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::route>>(AsyncSendRouteRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::route>> PrepareAsyncSendRoute(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::route>>(PrepareAsyncSendRouteRaw(context, request, cq));
    }
    ::grpc::Status SendOrder(::grpc::ClientContext* context, const ::route_planner::route& request, ::route_planner::car_order* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::car_order>> AsyncSendOrder(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::car_order>>(AsyncSendOrderRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::car_order>> PrepareAsyncSendOrder(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::route_planner::car_order>>(PrepareAsyncSendOrderRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void SendRoute(::grpc::ClientContext* context, const ::route_planner::request* request, ::route_planner::route* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void SendRoute(::grpc::ClientContext* context, const ::route_planner::request* request, ::route_planner::route* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void SendRoute(::grpc::ClientContext* context, const ::route_planner::request* request, ::route_planner::route* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      void SendOrder(::grpc::ClientContext* context, const ::route_planner::route* request, ::route_planner::car_order* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void SendOrder(::grpc::ClientContext* context, const ::route_planner::route* request, ::route_planner::car_order* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void SendOrder(::grpc::ClientContext* context, const ::route_planner::route* request, ::route_planner::car_order* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
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
    ::grpc::ClientAsyncResponseReader< ::route_planner::route>* AsyncSendRouteRaw(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::route_planner::route>* PrepareAsyncSendRouteRaw(::grpc::ClientContext* context, const ::route_planner::request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::route_planner::car_order>* AsyncSendOrderRaw(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::route_planner::car_order>* PrepareAsyncSendOrderRaw(::grpc::ClientContext* context, const ::route_planner::route& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SendRoute_;
    const ::grpc::internal::RpcMethod rpcmethod_SendOrder_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status SendRoute(::grpc::ServerContext* context, const ::route_planner::request* request, ::route_planner::route* response);
    virtual ::grpc::Status SendOrder(::grpc::ServerContext* context, const ::route_planner::route* request, ::route_planner::car_order* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SendRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendRoute() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SendRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRoute(::grpc::ServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendRoute(::grpc::ServerContext* context, ::route_planner::request* request, ::grpc::ServerAsyncResponseWriter< ::route_planner::route>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SendOrder : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendOrder() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_SendOrder() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendOrder(::grpc::ServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendOrder(::grpc::ServerContext* context, ::route_planner::route* request, ::grpc::ServerAsyncResponseWriter< ::route_planner::car_order>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SendRoute<WithAsyncMethod_SendOrder<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_SendRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_SendRoute() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::route_planner::request, ::route_planner::route>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::route_planner::request* request, ::route_planner::route* response) { return this->SendRoute(context, request, response); }));}
    void SetMessageAllocatorFor_SendRoute(
        ::grpc::experimental::MessageAllocator< ::route_planner::request, ::route_planner::route>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::route_planner::request, ::route_planner::route>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_SendRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRoute(::grpc::ServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SendRoute(
      ::grpc::CallbackServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SendRoute(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_SendOrder : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_SendOrder() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::route_planner::route, ::route_planner::car_order>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::route_planner::route* request, ::route_planner::car_order* response) { return this->SendOrder(context, request, response); }));}
    void SetMessageAllocatorFor_SendOrder(
        ::grpc::experimental::MessageAllocator< ::route_planner::route, ::route_planner::car_order>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(1);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::route_planner::route, ::route_planner::car_order>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_SendOrder() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendOrder(::grpc::ServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SendOrder(
      ::grpc::CallbackServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SendOrder(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_SendRoute<ExperimentalWithCallbackMethod_SendOrder<Service > > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_SendRoute<ExperimentalWithCallbackMethod_SendOrder<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SendRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendRoute() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SendRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRoute(::grpc::ServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SendOrder : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendOrder() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_SendOrder() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendOrder(::grpc::ServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendRoute() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SendRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRoute(::grpc::ServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendRoute(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendOrder : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendOrder() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_SendOrder() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendOrder(::grpc::ServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendOrder(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_SendRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_SendRoute() {
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
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendRoute(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_SendRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRoute(::grpc::ServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SendRoute(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SendRoute(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_SendOrder : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_SendOrder() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendOrder(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_SendOrder() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendOrder(::grpc::ServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SendOrder(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SendOrder(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendRoute() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::route_planner::request, ::route_planner::route>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::route_planner::request, ::route_planner::route>* streamer) {
                       return this->StreamedSendRoute(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendRoute(::grpc::ServerContext* /*context*/, const ::route_planner::request* /*request*/, ::route_planner::route* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendRoute(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::route_planner::request,::route_planner::route>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendOrder : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendOrder() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::route_planner::route, ::route_planner::car_order>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::route_planner::route, ::route_planner::car_order>* streamer) {
                       return this->StreamedSendOrder(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendOrder() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendOrder(::grpc::ServerContext* /*context*/, const ::route_planner::route* /*request*/, ::route_planner::car_order* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendOrder(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::route_planner::route,::route_planner::car_order>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SendRoute<WithStreamedUnaryMethod_SendOrder<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SendRoute<WithStreamedUnaryMethod_SendOrder<Service > > StreamedService;
};

}  // namespace route_planner


#endif  // GRPC_route_5fplanner_2eproto__INCLUDED