cmake_minimum_required(VERSION 3.5.1)

project(generate)

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  add_definitions(-D_WIN32_WINNT=0x600)
endif()

find_package(Threads REQUIRED)


  # This branch assumes that gRPC and all its dependencies are already installed
  # on this system, so they can be located by find_package().

  # Find Protobuf installation
  # Looks for protobuf-config.cmake file installed by Protobuf's cmake installation.
  set(protobuf_MODULE_COMPATIBLE TRUE)
  find_package(Protobuf CONFIG REQUIRED)
  message(STATUS "Using protobuf ${Protobuf_VERSION}")

  set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
  set(_REFLECTION gRPC::grpc++_reflection)
  if(CMAKE_CROSSCOMPILING)
    find_program(_PROTOBUF_PROTOC protoc)
  else()
    set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
  endif()

  # Find gRPC installation
  # Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
  find_package(gRPC CONFIG REQUIRED)
  message(STATUS "Using gRPC ${gRPC_VERSION}")

  set(_GRPC_GRPCPP gRPC::grpc++)
  if(CMAKE_CROSSCOMPILING)
    find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
  else() 
    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
  endif()


# # Proto file
# get_filename_component(rp_proto "${CMAKE_CURRENT_BINARY_DIR}/route_planner.proto" ABSOLUTE)
# get_filename_component(rp_proto_path "${rp_proto}" PATH)

# # Generated sources
# set(rp_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/route_planner.pb.cc")
# set(rp_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/route_planner.pb.h")
# set(rp_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/route_planner.grpc.pb.cc")
# set(rp_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/route_planner.grpc.pb.h")
# add_custom_command(
#       OUTPUT "${rp_proto_srcs}" "${rp_proto_hdrs}" "${rp_grpc_srcs}" "${rp_grpc_hdrs}"
#       COMMAND ${_PROTOBUF_PROTOC}
#       ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
#         --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
#         -I "${rp_proto_path}"
#         --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
#         "${rp_proto}"
#       DEPENDS "${rp_proto}")

# # Include generated *.pb.h files
# include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# # rp_grpc_proto
# add_library(rp_grpc_proto
#   ${rp_grpc_srcs}
#   ${rp_grpc_hdrs}
#   ${rp_proto_srcs}
#   ${rp_proto_hdrs})
# target_link_libraries(rp_grpc_proto
#   ${_REFLECTION}
#   ${_GRPC_GRPCPP}
#   ${_PROTOBUF_LIBPROTOBUF})

#   # Targets 
# foreach(_target )
#   add_executable(${_target} "${_target}.cc")
#   target_link_libraries(${_target}
#     rp_grpc_proto
#     ${_REFLECTION}
#     ${_GRPC_GRPCPP}
#     ${_PROTOBUF_LIBPROTOBUF})
# endforeach()



# #dbmanagement service for ordermanagement
# # Proto file
# get_filename_component(db_order_proto "${CMAKE_CURRENT_BINARY_DIR}/dbmanagement_ordermanagement.proto" ABSOLUTE)
# get_filename_component(db_order_proto_path "${db_order_proto}" PATH)

# # Generated sources
# set(db_order_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/dbmanagement_ordermanagement.pb.cc")
# set(db_order_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/dbmanagement_ordermanagement.pb.h")
# set(db_order_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/dbmanagement_ordermanagement.grpc.pb.cc")
# set(db_order_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/dbmanagement_ordermanagement.grpc.pb.h")
# add_custom_command(
#       OUTPUT "${db_order_proto_srcs}" "${db_order_proto_hdrs}" "${db_order_grpc_srcs}" "${db_order_grpc_hdrs}"
#       COMMAND ${_PROTOBUF_PROTOC}
#       ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
#         --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
#         -I "${db_order_proto_path}"
#         --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
#         "${db_order_proto}"
#       DEPENDS "${db_order_proto}")

# # Include generated *.pb.h files
# include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# # db_grpc_proto
# add_library(db_order_proto
#   ${db_order_proto_srcs}
#   ${db_order_proto_hdrs}
#   ${db_order_grpc_srcs}
#   ${db_order_grpc_hdrs})
# target_link_libraries(db_order_proto
#   ${_REFLECTION}
#   ${_GRPC_GRPCPP}
#   ${_PROTOBUF_LIBPROTOBUF})

#   # Targets 
# foreach(_target )
#   add_executable(${_target} "${_target}.cc")
#   target_link_libraries(${_target}
#     db_order_proto
#     ${_REFLECTION}
#     ${_GRPC_GRPCPP}
#     ${_PROTOBUF_LIBPROTOBUF})
# endforeach()

# #ordermanagement service for ordersystem
# # Proto file
# get_filename_component(order_ordersys_proto "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_ordersystem.proto" ABSOLUTE)
# get_filename_component(order_ordersys_proto_path "${order_ordersys_proto}" PATH)

# # Generated sources
# set(order_ordersys_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_ordersystem.pb.cc")
# set(order_ordersys_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_ordersystem.pb.h")
# set(order_ordersys_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_ordersystem.grpc.pb.cc")
# set(order_ordersys_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_ordersystem.grpc.pb.h")
# add_custom_command(
#       OUTPUT "${order_ordersys_proto_srcs}" "${order_ordersys_proto_hdrs}" "${order_ordersys_grpc_srcs}" "${order_ordersys_grpc_hdrs}"
#       COMMAND ${_PROTOBUF_PROTOC}
#       ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
#         --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
#         -I "${order_ordersys_proto_path}"
#         --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
#         "${order_ordersys_proto}"
#       DEPENDS "${order_ordersys_proto}")

# # Include generated *.pb.h files
# include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# # db_grpc_proto
# add_library(order_ordersys_proto
#   ${order_ordersys_proto_srcs}
#   ${order_ordersys_proto_hdrs}
#   ${order_ordersys_grpc_srcs}
#   ${order_ordersys_grpc_hdrs})
# target_link_libraries(order_ordersys_proto
#   ${_REFLECTION}
#   ${_GRPC_GRPCPP}
#   ${_PROTOBUF_LIBPROTOBUF})

#   # Targets 
# foreach(_target )
#   add_executable(${_target} "${_target}.cc")
#   target_link_libraries(${_target}
#   order_ordersys_proto
#     ${_REFLECTION}
#     ${_GRPC_GRPCPP}
#     ${_PROTOBUF_LIBPROTOBUF})
# endforeach()

# #ordermanagement service for jobmanagement
# # Proto file
# get_filename_component(order_job_proto "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_jobmanagement.proto" ABSOLUTE)
# get_filename_component(order_job_proto_path "${order_job_proto}" PATH)

# # Generated sources
# set(order_job_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_jobmanagement.pb.cc")
# set(order_job_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_jobmanagement.pb.h")
# set(order_job_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_jobmanagement.grpc.pb.cc")
# set(order_job_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/ordermanagement_jobmanagement.grpc.pb.h")
# add_custom_command(
#       OUTPUT "${order_job_proto_srcs}" "${order_job_proto_hdrs}" "${order_job_grpc_srcs}" "${order_job_grpc_hdrs}"
#       COMMAND ${_PROTOBUF_PROTOC}
#       ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
#         --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
#         -I "${order_job_proto_path}"
#         --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
#         "${order_job_proto}"
#       DEPENDS "${order_job_proto}")

# # Include generated *.pb.h files
# include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# # db_grpc_proto
# add_library(order_job_proto
#   ${order_job_proto_srcs}
#   ${order_job_proto_hdrs}
#   ${order_job_grpc_srcs}
#   ${order_job_grpc_hdrs})
# target_link_libraries(order_job_proto
#   ${_REFLECTION}
#   ${_GRPC_GRPCPP}
#   ${_PROTOBUF_LIBPROTOBUF})

#   # Targets 
# foreach(_target )
#   add_executable(${_target} "${_target}.cc")
#   target_link_libraries(${_target}
#   order_job_proto
#     ${_REFLECTION}
#     ${_GRPC_GRPCPP}
#     ${_PROTOBUF_LIBPROTOBUF})
# endforeach()

#jobmanagement service for ordermanagement
# Proto file
get_filename_component(job_order_proto "${CMAKE_CURRENT_BINARY_DIR}/jobmanagement_ordermanagement.proto" ABSOLUTE)
get_filename_component(job_order_proto_path "${job_order_proto}" PATH)

# Generated sources
set(job_order_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/jobmanagement_ordermanagement.pb.cc")
set(job_order_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/jobmanagement_ordermanagement.pb.h")
set(job_order_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/jobmanagement_ordermanagement.grpc.pb.cc")
set(job_order_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/jobmanagement_ordermanagement.grpc.pb.h")
add_custom_command(
      OUTPUT "${job_order_proto_srcs}" "${job_order_proto_hdrs}" "${job_order_grpc_srcs}" "${job_order_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${job_order_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${job_order_proto}"
      DEPENDS "${job_order_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# db_grpc_proto
add_library(job_order_proto
  ${job_order_proto_srcs}
  ${job_order_proto_hdrs}
  ${job_order_grpc_srcs}
  ${job_order_grpc_hdrs})
target_link_libraries(job_order_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

  # Targets 
foreach(_target )
  add_executable(${_target} "${_target}.cc")
  target_link_libraries(${_target}
  order_job_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()