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
include XML/CMakeFiles/xml.dir/depend.make

# Include the progress variables for this target.
include XML/CMakeFiles/xml.dir/progress.make

# Include the compile flags for this target's objects.
include XML/CMakeFiles/xml.dir/flags.make

XML/CMakeFiles/xml.dir/tinyxml2.cpp.o: XML/CMakeFiles/xml.dir/flags.make
XML/CMakeFiles/xml.dir/tinyxml2.cpp.o: ../XML/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object XML/CMakeFiles/xml.dir/tinyxml2.cpp.o"
	cd /root/source/simulator_server_track/route_plan/build/XML && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xml.dir/tinyxml2.cpp.o -c /root/source/simulator_server_track/route_plan/XML/tinyxml2.cpp

XML/CMakeFiles/xml.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xml.dir/tinyxml2.cpp.i"
	cd /root/source/simulator_server_track/route_plan/build/XML && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/XML/tinyxml2.cpp > CMakeFiles/xml.dir/tinyxml2.cpp.i

XML/CMakeFiles/xml.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xml.dir/tinyxml2.cpp.s"
	cd /root/source/simulator_server_track/route_plan/build/XML && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/XML/tinyxml2.cpp -o CMakeFiles/xml.dir/tinyxml2.cpp.s

XML/CMakeFiles/xml.dir/xmltomap.cc.o: XML/CMakeFiles/xml.dir/flags.make
XML/CMakeFiles/xml.dir/xmltomap.cc.o: ../XML/xmltomap.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object XML/CMakeFiles/xml.dir/xmltomap.cc.o"
	cd /root/source/simulator_server_track/route_plan/build/XML && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xml.dir/xmltomap.cc.o -c /root/source/simulator_server_track/route_plan/XML/xmltomap.cc

XML/CMakeFiles/xml.dir/xmltomap.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xml.dir/xmltomap.cc.i"
	cd /root/source/simulator_server_track/route_plan/build/XML && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/XML/xmltomap.cc > CMakeFiles/xml.dir/xmltomap.cc.i

XML/CMakeFiles/xml.dir/xmltomap.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xml.dir/xmltomap.cc.s"
	cd /root/source/simulator_server_track/route_plan/build/XML && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/XML/xmltomap.cc -o CMakeFiles/xml.dir/xmltomap.cc.s

# Object files for target xml
xml_OBJECTS = \
"CMakeFiles/xml.dir/tinyxml2.cpp.o" \
"CMakeFiles/xml.dir/xmltomap.cc.o"

# External object files for target xml
xml_EXTERNAL_OBJECTS =

XML/libxml.a: XML/CMakeFiles/xml.dir/tinyxml2.cpp.o
XML/libxml.a: XML/CMakeFiles/xml.dir/xmltomap.cc.o
XML/libxml.a: XML/CMakeFiles/xml.dir/build.make
XML/libxml.a: XML/CMakeFiles/xml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libxml.a"
	cd /root/source/simulator_server_track/route_plan/build/XML && $(CMAKE_COMMAND) -P CMakeFiles/xml.dir/cmake_clean_target.cmake
	cd /root/source/simulator_server_track/route_plan/build/XML && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
XML/CMakeFiles/xml.dir/build: XML/libxml.a

.PHONY : XML/CMakeFiles/xml.dir/build

XML/CMakeFiles/xml.dir/clean:
	cd /root/source/simulator_server_track/route_plan/build/XML && $(CMAKE_COMMAND) -P CMakeFiles/xml.dir/cmake_clean.cmake
.PHONY : XML/CMakeFiles/xml.dir/clean

XML/CMakeFiles/xml.dir/depend:
	cd /root/source/simulator_server_track/route_plan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/source/simulator_server_track/route_plan /root/source/simulator_server_track/route_plan/XML /root/source/simulator_server_track/route_plan/build /root/source/simulator_server_track/route_plan/build/XML /root/source/simulator_server_track/route_plan/build/XML/CMakeFiles/xml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : XML/CMakeFiles/xml.dir/depend

