cmake_minimum_required(VERSION 3.5.1)

project(mongodbmanager)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

add_library(mongodbmanager mongodbmanager.cc mongodbmanager.h dbmanagement_server.h dbmanagement_server.cc 
 dbmanagement_ordermanagement.grpc.pb.h dbmanagement_ordermanagement.grpc.pb.cc dbmanagement_ordermanagement.pb.h dbmanagement_ordermanagement.pb.cc
)
install(TARGETS mongodbmanager DESTINATION lib)
install(FILES mongodbmanager.h dbmanagement_server.h DESTINATION include)

target_link_libraries(mongodbmanager ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(mongodbmanager ${LIBBSONCXX_LIBRARIES})

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC REQUIRED)
include_directories("/usr/local/include/grpc")
include_directories("/usr/local/include/grpc++")
include_directories("/usr/local/include/grpcpp")
target_link_libraries(mongodbmanager protobuf::libprotobuf gRPC::grpc++ gRPC::grpc++_reflection)

find_package(Threads REQUIRED)
target_link_libraries(mongodbmanager Threads::Threads)