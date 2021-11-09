add_library(core_connect core_connect.h core_connect.cc)

install(TARGETS core_connect DESTINATION lib)
install(FILES core_connect.h DESTINATION include)