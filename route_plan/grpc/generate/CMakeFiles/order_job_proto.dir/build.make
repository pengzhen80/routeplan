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
CMAKE_SOURCE_DIR = /root/source/simulator_server_track/route_plan/grpc/generate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/source/simulator_server_track/route_plan/grpc/generate

# Include any dependencies generated for this target.
include CMakeFiles/order_job_proto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/order_job_proto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/order_job_proto.dir/flags.make

ordermanagement_jobmanagement.pb.cc: ordermanagement_jobmanagement.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/source/simulator_server_track/route_plan/grpc/generate/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ordermanagement_jobmanagement.pb.cc, ordermanagement_jobmanagement.pb.h, ordermanagement_jobmanagement.grpc.pb.cc, ordermanagement_jobmanagement.grpc.pb.h"
	/root/.local/bin/protoc-3.15.2.0 --grpc_out /root/source/simulator_server_track/route_plan/grpc/generate --cpp_out /root/source/simulator_server_track/route_plan/grpc/generate -I /root/source/simulator_server_track/route_plan/grpc/generate --plugin=protoc-gen-grpc="/root/.local/bin/grpc_cpp_plugin" /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.proto

ordermanagement_jobmanagement.pb.h: ordermanagement_jobmanagement.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate ordermanagement_jobmanagement.pb.h

ordermanagement_jobmanagement.grpc.pb.cc: ordermanagement_jobmanagement.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate ordermanagement_jobmanagement.grpc.pb.cc

ordermanagement_jobmanagement.grpc.pb.h: ordermanagement_jobmanagement.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate ordermanagement_jobmanagement.grpc.pb.h

CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.o: CMakeFiles/order_job_proto.dir/flags.make
CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.o: ordermanagement_jobmanagement.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/grpc/generate/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.o -c /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.pb.cc

CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.pb.cc > CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.i

CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.pb.cc -o CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.s

CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.o: CMakeFiles/order_job_proto.dir/flags.make
CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.o: ordermanagement_jobmanagement.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/grpc/generate/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.o -c /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.grpc.pb.cc

CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.grpc.pb.cc > CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.i

CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/grpc/generate/ordermanagement_jobmanagement.grpc.pb.cc -o CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.s

# Object files for target order_job_proto
order_job_proto_OBJECTS = \
"CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.o" \
"CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.o"

# External object files for target order_job_proto
order_job_proto_EXTERNAL_OBJECTS =

liborder_job_proto.a: CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.pb.cc.o
liborder_job_proto.a: CMakeFiles/order_job_proto.dir/ordermanagement_jobmanagement.grpc.pb.cc.o
liborder_job_proto.a: CMakeFiles/order_job_proto.dir/build.make
liborder_job_proto.a: CMakeFiles/order_job_proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/source/simulator_server_track/route_plan/grpc/generate/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library liborder_job_proto.a"
	$(CMAKE_COMMAND) -P CMakeFiles/order_job_proto.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/order_job_proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/order_job_proto.dir/build: liborder_job_proto.a

.PHONY : CMakeFiles/order_job_proto.dir/build

CMakeFiles/order_job_proto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/order_job_proto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/order_job_proto.dir/clean

CMakeFiles/order_job_proto.dir/depend: ordermanagement_jobmanagement.pb.cc
CMakeFiles/order_job_proto.dir/depend: ordermanagement_jobmanagement.pb.h
CMakeFiles/order_job_proto.dir/depend: ordermanagement_jobmanagement.grpc.pb.cc
CMakeFiles/order_job_proto.dir/depend: ordermanagement_jobmanagement.grpc.pb.h
	cd /root/source/simulator_server_track/route_plan/grpc/generate && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/source/simulator_server_track/route_plan/grpc/generate /root/source/simulator_server_track/route_plan/grpc/generate /root/source/simulator_server_track/route_plan/grpc/generate /root/source/simulator_server_track/route_plan/grpc/generate /root/source/simulator_server_track/route_plan/grpc/generate/CMakeFiles/order_job_proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/order_job_proto.dir/depend
