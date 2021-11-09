add_library(xml tinyxml2.cpp tinyxml2.h xmltomap.cc xmltomap.h)

install(TARGETS xml DESTINATION lib)
install(FILES tinyxml2.h xmltomap.h DESTINATION include)
