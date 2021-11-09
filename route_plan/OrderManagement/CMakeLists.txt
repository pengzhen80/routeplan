find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC REQUIRED)
include_directories("/usr/local/include/grpc")
include_directories("/usr/local/include/grpc++")
include_directories("/usr/local/include/grpcpp")

add_subdirectory(grpc_files)
add_subdirectory(Core)
add_library(ordermanagement ordermanagement.cc ordermanagement.h 
ordermanagement_client.h ordermanagement_client.cc 
ordermanagement_server.h ordermanagement_server.cc
ordermanagement_jobmanagement.grpc.pb.h ordermanagement_jobmanagement.grpc.pb.cc ordermanagement_jobmanagement.pb.h ordermanagement_jobmanagement.pb.cc
ordermanagement_ordersystem.grpc.pb.h ordermanagement_ordersystem.grpc.pb.cc ordermanagement_ordersystem.pb.h ordermanagement_ordersystem.pb.cc
Protocol_SendMealSystem.h TinkerBoardServer.h TinkerBoardServer.cc
)

install(TARGETS ordermanagement DESTINATION lib)
install(FILES ordermanagement.h ordermanagement_server.h ordermanagement_client.h TinkerBoardServer.h DESTINATION include)


target_link_libraries(ordermanagement protobuf::libprotobuf gRPC::grpc++ gRPC::grpc++_reflection )

find_package(Threads REQUIRED)
target_link_libraries(ordermanagement Threads::Threads)

target_link_libraries(ordermanagement grpc_dbmanagement)
