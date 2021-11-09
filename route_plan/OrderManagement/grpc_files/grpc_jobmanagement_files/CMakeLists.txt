add_library(grpc_jobmanagement jobmanagement_ordermanagement.grpc.pb.h jobmanagement_ordermanagement.grpc.pb.cc 
jobmanagement_ordermanagement.pb.h jobmanagement_ordermanagement.pb.cc)

install(TARGETS grpc_jobmanagement DESTINATION lib)
install(FILES jobmanagement_ordermanagement.grpc.pb.h DESTINATION include)