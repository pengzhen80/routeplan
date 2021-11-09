add_library(server CallCarServer.cc CallCarServer.h )
install(TARGETS server DESTINATION lib)
install(FILES CallCarServer.h  DESTINATION include)