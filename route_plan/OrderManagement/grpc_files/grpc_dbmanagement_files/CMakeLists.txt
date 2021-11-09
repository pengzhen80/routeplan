add_library(grpc_dbmanagement dbmanagement_ordermanagement.grpc.pb.h dbmanagement_ordermanagement.grpc.pb.cc 
dbmanagement_ordermanagement.pb.h dbmanagement_ordermanagement.pb.cc)

install(TARGETS grpc_dbmanagement DESTINATION lib)
install(FILES dbmanagement_ordermanagement.grpc.pb.h DESTINATION include)