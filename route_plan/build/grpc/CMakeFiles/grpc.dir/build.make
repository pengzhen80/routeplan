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
CMAKE_BINARY_DIR = /root/source/simulator_server_track/route_plan/build

# Include any dependencies generated for this target.
include grpc/CMakeFiles/grpc.dir/depend.make

# Include the progress variables for this target.
include grpc/CMakeFiles/grpc.dir/progress.make

# Include the compile flags for this target's objects.
include grpc/CMakeFiles/grpc.dir/flags.make

grpc/CMakeFiles/grpc.dir/client.cc.o: grpc/CMakeFiles/grpc.dir/flags.make
grpc/CMakeFiles/grpc.dir/client.cc.o: ../grpc/client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object grpc/CMakeFiles/grpc.dir/client.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grpc.dir/client.cc.o -c /root/source/simulator_server_track/route_plan/grpc/client.cc

grpc/CMakeFiles/grpc.dir/client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grpc.dir/client.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/grpc/client.cc > CMakeFiles/grpc.dir/client.cc.i

grpc/CMakeFiles/grpc.dir/client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grpc.dir/client.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/grpc/client.cc -o CMakeFiles/grpc.dir/client.cc.s

grpc/CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.o: grpc/CMakeFiles/grpc.dir/flags.make
grpc/CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.o: ../grpc/route_planner.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object grpc/CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.o -c /root/source/simulator_server_track/route_plan/grpc/route_planner.grpc.pb.cc

grpc/CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/grpc/route_planner.grpc.pb.cc > CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.i

grpc/CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/grpc/route_planner.grpc.pb.cc -o CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.s

grpc/CMakeFiles/grpc.dir/route_planner.pb.cc.o: grpc/CMakeFiles/grpc.dir/flags.make
grpc/CMakeFiles/grpc.dir/route_planner.pb.cc.o: ../grpc/route_planner.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object grpc/CMakeFiles/grpc.dir/route_planner.pb.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grpc.dir/route_planner.pb.cc.o -c /root/source/simulator_server_track/route_plan/grpc/route_planner.pb.cc

grpc/CMakeFiles/grpc.dir/route_planner.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grpc.dir/route_planner.pb.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/grpc/route_planner.pb.cc > CMakeFiles/grpc.dir/route_planner.pb.cc.i

grpc/CMakeFiles/grpc.dir/route_planner.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grpc.dir/route_planner.pb.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/grpc && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/grpc/route_planner.pb.cc -o CMakeFiles/grpc.dir/route_planner.pb.cc.s

# Object files for target grpc
grpc_OBJECTS = \
"CMakeFiles/grpc.dir/client.cc.o" \
"CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.o" \
"CMakeFiles/grpc.dir/route_planner.pb.cc.o"

# External object files for target grpc
grpc_EXTERNAL_OBJECTS =

grpc/libgrpc.a: grpc/CMakeFiles/grpc.dir/client.cc.o
grpc/libgrpc.a: grpc/CMakeFiles/grpc.dir/route_planner.grpc.pb.cc.o
grpc/libgrpc.a: grpc/CMakeFiles/grpc.dir/route_planner.pb.cc.o
grpc/libgrpc.a: grpc/CMakeFiles/grpc.dir/build.make
grpc/libgrpc.a: grpc/CMakeFiles/grpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libgrpc.a"
	cd /root/source/simulator_server_track/route_plan/build/grpc && $(CMAKE_COMMAND) -P CMakeFiles/grpc.dir/cmake_clean_target.cmake
	cd /root/source/simulator_server_track/route_plan/build/grpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
grpc/CMakeFiles/grpc.dir/build: grpc/libgrpc.a

.PHONY : grpc/CMakeFiles/grpc.dir/build

grpc/CMakeFiles/grpc.dir/clean:
	cd /root/source/simulator_server_track/route_plan/build/grpc && $(CMAKE_COMMAND) -P CMakeFiles/grpc.dir/cmake_clean.cmake
.PHONY : grpc/CMakeFiles/grpc.dir/clean

grpc/CMakeFiles/grpc.dir/depend:
	cd /root/source/simulator_server_track/route_plan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/source/simulator_server_track/route_plan /root/source/simulator_server_track/route_plan/grpc /root/source/simulator_server_track/route_plan/build /root/source/simulator_server_track/route_plan/build/grpc /root/source/simulator_server_track/route_plan/build/grpc/CMakeFiles/grpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : grpc/CMakeFiles/grpc.dir/depend

