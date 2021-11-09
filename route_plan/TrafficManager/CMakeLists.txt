add_library(trafficmanager trafficmanager.cc trafficmanager.h)

install(TARGETS trafficmanager DESTINATION lib)
install(FILES trafficmanager.h DESTINATION include)