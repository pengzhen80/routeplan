# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/source/simulator_server_track/route_plan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/source/simulator_server_track/route_plan/out/build

# Include any dependencies generated for this target.
include Car/CMakeFiles/car.dir/depend.make

# Include the progress variables for this target.
include Car/CMakeFiles/car.dir/progress.make

# Include the compile flags for this target's objects.
include Car/CMakeFiles/car.dir/flags.make

Car/CMakeFiles/car.dir/car.cc.o: Car/CMakeFiles/car.dir/flags.make
Car/CMakeFiles/car.dir/car.cc.o: ../../Car/car.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Car/CMakeFiles/car.dir/car.cc.o"
	cd /root/source/simulator_server_track/route_plan/out/build/Car && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/car.dir/car.cc.o -c /root/source/simulator_server_track/route_plan/Car/car.cc

Car/CMakeFiles/car.dir/car.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/car.dir/car.cc.i"
	cd /root/source/simulator_server_track/route_plan/out/build/Car && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/Car/car.cc > CMakeFiles/car.dir/car.cc.i

Car/CMakeFiles/car.dir/car.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/car.dir/car.cc.s"
	cd /root/source/simulator_server_track/route_plan/out/build/Car && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/Car/car.cc -o CMakeFiles/car.dir/car.cc.s

# Object files for target car
car_OBJECTS = \
"CMakeFiles/car.dir/car.cc.o"

# External object files for target car
car_EXTERNAL_OBJECTS =

Car/libcar.a: Car/CMakeFiles/car.dir/car.cc.o
Car/libcar.a: Car/CMakeFiles/car.dir/build.make
Car/libcar.a: Car/CMakeFiles/car.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/source/simulator_server_track/route_plan/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcar.a"
	cd /root/source/simulator_server_track/route_plan/out/build/Car && $(CMAKE_COMMAND) -P CMakeFiles/car.dir/cmake_clean_target.cmake
	cd /root/source/simulator_server_track/route_plan/out/build/Car && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/car.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Car/CMakeFiles/car.dir/build: Car/libcar.a

.PHONY : Car/CMakeFiles/car.dir/build

Car/CMakeFiles/car.dir/clean:
	cd /root/source/simulator_server_track/route_plan/out/build/Car && $(CMAKE_COMMAND) -P CMakeFiles/car.dir/cmake_clean.cmake
.PHONY : Car/CMakeFiles/car.dir/clean

Car/CMakeFiles/car.dir/depend:
	cd /root/source/simulator_server_track/route_plan/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/source/simulator_server_track/route_plan /root/source/simulator_server_track/route_plan/Car /root/source/simulator_server_track/route_plan/out/build /root/source/simulator_server_track/route_plan/out/build/Car /root/source/simulator_server_track/route_plan/out/build/Car/CMakeFiles/car.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Car/CMakeFiles/car.dir/depend
