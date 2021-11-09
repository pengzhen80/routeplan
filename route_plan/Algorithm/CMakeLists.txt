add_library(astar Astar.cc Astar.h CoAstar.cc CoAstar.h)

install(TARGETS astar DESTINATION lib)
install(FILES Astar.h CoAstar.h DESTINATION include)