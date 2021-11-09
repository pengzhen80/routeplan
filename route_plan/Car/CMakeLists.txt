add_library(car car.cc car.h)

install(TARGETS car DESTINATION lib)
install(FILES car.h DESTINATION include)