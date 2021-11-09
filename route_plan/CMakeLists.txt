cmake_minimum_required(VERSION 3.5.1)

project(route_plan)
  
add_executable(${PROJECT_NAME} main.cc)

add_subdirectory(Algorithm)
#add_subdirectory(grpc)
add_subdirectory(XML)
add_subdirectory(CallCar)
add_subdirectory(Map)
add_subdirectory(Car)
add_subdirectory(TrafficManager)
add_subdirectory(OrderManagement)
add_subdirectory(DBManagement)
add_subdirectory(JobManagement)
add_subdirectory(ConfigurationManager)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Algorithm
#    PUBLIC grpc
    PUBLIC XML
    PUBLIC CallCar 
    PUBLIC Map
    PUBLIC Car
    PUBLIC TrafficManager
    PUBLIC OrderManagement
    PUBLIC DBManagement
    PUBLIC JobManagement
    PUBLIC ConfigurationManager
)

target_link_directories(${PROJECT_NAME}
    PRIVATE Algorithm
#    PRIVATE grpc
    PRIVATE XML 
    PRIVATE CallCar
    PRIVATE Map
    PRIVATE Car
    PRIVATE TrafficManager
    PRIVATE OrderManagement
    PRIVATE DBManagement
    PRIVATE JobManagement
    PRIVATE ConfigurationManager
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} astar  xml server map car trafficmanager ordermanagement mongodbmanager jobmanagement configurationmanager Threads::Threads)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC REQUIRED)
include_directories("/usr/local/include/grpc")
include_directories("/usr/local/include/grpc++")
include_directories("/usr/local/include/grpcpp")