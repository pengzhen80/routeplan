add_library(configurationmanager configurationmanager.cc configurationmanager.h carmanager.h carmanager.cc mapmanager.h mapmanager.cc)

install(TARGETS configurationmanager DESTINATION lib)
install(FILES configurationmanager.h DESTINATION include)