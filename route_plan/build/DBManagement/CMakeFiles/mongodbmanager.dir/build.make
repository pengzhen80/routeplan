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
include DBManagement/CMakeFiles/mongodbmanager.dir/depend.make

# Include the progress variables for this target.
include DBManagement/CMakeFiles/mongodbmanager.dir/progress.make

# Include the compile flags for this target's objects.
include DBManagement/CMakeFiles/mongodbmanager.dir/flags.make

DBManagement/CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.o: DBManagement/CMakeFiles/mongodbmanager.dir/flags.make
DBManagement/CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.o: ../DBManagement/mongodbmanager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DBManagement/CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.o -c /root/source/simulator_server_track/route_plan/DBManagement/mongodbmanager.cc

DBManagement/CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/DBManagement/mongodbmanager.cc > CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.i

DBManagement/CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/DBManagement/mongodbmanager.cc -o CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.s

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.o: DBManagement/CMakeFiles/mongodbmanager.dir/flags.make
DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.o: ../DBManagement/dbmanagement_server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.o -c /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_server.cc

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_server.cc > CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.i

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_server.cc -o CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.s

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.o: DBManagement/CMakeFiles/mongodbmanager.dir/flags.make
DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.o: ../DBManagement/dbmanagement_ordermanagement.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.o -c /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_ordermanagement.grpc.pb.cc

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_ordermanagement.grpc.pb.cc > CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.i

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_ordermanagement.grpc.pb.cc -o CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.s

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.o: DBManagement/CMakeFiles/mongodbmanager.dir/flags.make
DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.o: ../DBManagement/dbmanagement_ordermanagement.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.o -c /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_ordermanagement.pb.cc

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_ordermanagement.pb.cc > CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.i

DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/DBManagement/dbmanagement_ordermanagement.pb.cc -o CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.s

# Object files for target mongodbmanager
mongodbmanager_OBJECTS = \
"CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.o" \
"CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.o" \
"CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.o" \
"CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.o"

# External object files for target mongodbmanager
mongodbmanager_EXTERNAL_OBJECTS =

DBManagement/libmongodbmanager.a: DBManagement/CMakeFiles/mongodbmanager.dir/mongodbmanager.cc.o
DBManagement/libmongodbmanager.a: DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_server.cc.o
DBManagement/libmongodbmanager.a: DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.grpc.pb.cc.o
DBManagement/libmongodbmanager.a: DBManagement/CMakeFiles/mongodbmanager.dir/dbmanagement_ordermanagement.pb.cc.o
DBManagement/libmongodbmanager.a: DBManagement/CMakeFiles/mongodbmanager.dir/build.make
DBManagement/libmongodbmanager.a: DBManagement/CMakeFiles/mongodbmanager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libmongodbmanager.a"
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && $(CMAKE_COMMAND) -P CMakeFiles/mongodbmanager.dir/cmake_clean_target.cmake
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mongodbmanager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DBManagement/CMakeFiles/mongodbmanager.dir/build: DBManagement/libmongodbmanager.a

.PHONY : DBManagement/CMakeFiles/mongodbmanager.dir/build

DBManagement/CMakeFiles/mongodbmanager.dir/clean:
	cd /root/source/simulator_server_track/route_plan/build/DBManagement && $(CMAKE_COMMAND) -P CMakeFiles/mongodbmanager.dir/cmake_clean.cmake
.PHONY : DBManagement/CMakeFiles/mongodbmanager.dir/clean

DBManagement/CMakeFiles/mongodbmanager.dir/depend:
	cd /root/source/simulator_server_track/route_plan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/source/simulator_server_track/route_plan /root/source/simulator_server_track/route_plan/DBManagement /root/source/simulator_server_track/route_plan/build /root/source/simulator_server_track/route_plan/build/DBManagement /root/source/simulator_server_track/route_plan/build/DBManagement/CMakeFiles/mongodbmanager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DBManagement/CMakeFiles/mongodbmanager.dir/depend

