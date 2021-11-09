find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC REQUIRED)
include_directories("/usr/local/include/grpc")
include_directories("/usr/local/include/grpc++")
include_directories("/usr/local/include/grpcpp")

add_subdirectory(grpc_files)

add_library(jobmanagement jobmanagement.cc jobmanagement.h jobmanagement_server.h jobmanagement_server.cc jobmanagement_common.h)

install(TARGETS jobmanagement DESTINATION lib)
install(FILES jobmanagement.h jobmanagement_server.h DESTINATION include)

target_link_libraries(jobmanagement protobuf::libprotobuf gRPC::grpc++ gRPC::grpc++_reflection )

find_package(Threads REQUIRED)
target_link_libraries(jobmanagement Threads::Threads)

target_link_libraries(jobmanagement jobmanagement_ordermanagement)