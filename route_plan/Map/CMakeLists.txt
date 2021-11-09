add_library(map map.cc map.h)

install(TARGETS map DESTINATION lib)
install(FILES map.h DESTINATION include)