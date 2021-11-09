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
include CMakeFiles/route_plan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/route_plan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/route_plan.dir/flags.make

CMakeFiles/route_plan.dir/main.cc.o: CMakeFiles/route_plan.dir/flags.make
CMakeFiles/route_plan.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/route_plan.dir/main.cc.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/route_plan.dir/main.cc.o -c /root/source/simulator_server_track/route_plan/main.cc

CMakeFiles/route_plan.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/route_plan.dir/main.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/source/simulator_server_track/route_plan/main.cc > CMakeFiles/route_plan.dir/main.cc.i

CMakeFiles/route_plan.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/route_plan.dir/main.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/source/simulator_server_track/route_plan/main.cc -o CMakeFiles/route_plan.dir/main.cc.s

# Object files for target route_plan
route_plan_OBJECTS = \
"CMakeFiles/route_plan.dir/main.cc.o"

# External object files for target route_plan
route_plan_EXTERNAL_OBJECTS =

route_plan: CMakeFiles/route_plan.dir/main.cc.o
route_plan: CMakeFiles/route_plan.dir/build.make
route_plan: Algorithm/libastar.a
route_plan: XML/libxml.a
route_plan: CallCar/libserver.a
route_plan: Map/libmap.a
route_plan: Car/libcar.a
route_plan: TrafficManager/libtrafficmanager.a
route_plan: OrderManagement/libordermanagement.a
route_plan: DBManagement/libmongodbmanager.a
route_plan: JobManagement/libjobmanagement.a
route_plan: ConfigurationManager/libconfigurationmanager.a
route_plan: /usr/local/lib/libgrpc++_reflection.a
route_plan: /usr/local/lib/libgrpc++.a
route_plan: /usr/local/lib/libprotobuf.a
route_plan: /usr/local/lib/libgrpc.a
route_plan: /usr/local/lib/libz.a
route_plan: /usr/local/lib/libcares.a
route_plan: /usr/local/lib/libaddress_sorting.a
route_plan: /usr/local/lib/libre2.a
route_plan: /usr/local/lib/libupb.a
route_plan: /usr/local/lib/libabsl_hash.a
route_plan: /usr/local/lib/libabsl_city.a
route_plan: /usr/local/lib/libabsl_raw_hash_set.a
route_plan: /usr/local/lib/libabsl_hashtablez_sampler.a
route_plan: /usr/local/lib/libabsl_exponential_biased.a
route_plan: /usr/local/lib/libabsl_statusor.a
route_plan: /usr/local/lib/libabsl_bad_variant_access.a
route_plan: /usr/local/lib/libgpr.a
route_plan: /usr/local/lib/libabsl_status.a
route_plan: /usr/local/lib/libabsl_cord.a
route_plan: /usr/local/lib/libabsl_str_format_internal.a
route_plan: /usr/local/lib/libabsl_synchronization.a
route_plan: /usr/local/lib/libabsl_stacktrace.a
route_plan: /usr/local/lib/libabsl_symbolize.a
route_plan: /usr/local/lib/libabsl_debugging_internal.a
route_plan: /usr/local/lib/libabsl_demangle_internal.a
route_plan: /usr/local/lib/libabsl_graphcycles_internal.a
route_plan: /usr/local/lib/libabsl_malloc_internal.a
route_plan: /usr/local/lib/libabsl_time.a
route_plan: /usr/local/lib/libabsl_strings.a
route_plan: /usr/local/lib/libabsl_throw_delegate.a
route_plan: /usr/local/lib/libabsl_strings_internal.a
route_plan: /usr/local/lib/libabsl_base.a
route_plan: /usr/local/lib/libabsl_spinlock_wait.a
route_plan: /usr/local/lib/libabsl_int128.a
route_plan: /usr/local/lib/libabsl_civil_time.a
route_plan: /usr/local/lib/libabsl_time_zone.a
route_plan: /usr/local/lib/libabsl_bad_optional_access.a
route_plan: /usr/local/lib/libabsl_raw_logging_internal.a
route_plan: /usr/local/lib/libabsl_log_severity.a
route_plan: /usr/local/lib/libssl.a
route_plan: /usr/local/lib/libcrypto.a
route_plan: OrderManagement/grpc_files/grpc_dbmanagement_files/libgrpc_dbmanagement.a
route_plan: /usr/local/lib/libmongocxx.so
route_plan: /usr/local/lib/libbsoncxx.so
route_plan: /usr/local/lib/libgrpc++_reflection.a
route_plan: /usr/local/lib/libgrpc++.a
route_plan: /usr/local/lib/libprotobuf.a
route_plan: /usr/local/lib/libgrpc.a
route_plan: /usr/local/lib/libz.a
route_plan: /usr/local/lib/libcares.a
route_plan: /usr/local/lib/libaddress_sorting.a
route_plan: /usr/local/lib/libre2.a
route_plan: /usr/local/lib/libupb.a
route_plan: /usr/local/lib/libabsl_hash.a
route_plan: /usr/local/lib/libabsl_city.a
route_plan: /usr/local/lib/libabsl_raw_hash_set.a
route_plan: /usr/local/lib/libabsl_hashtablez_sampler.a
route_plan: /usr/local/lib/libabsl_exponential_biased.a
route_plan: /usr/local/lib/libabsl_statusor.a
route_plan: /usr/local/lib/libabsl_bad_variant_access.a
route_plan: /usr/local/lib/libgpr.a
route_plan: /usr/local/lib/libabsl_status.a
route_plan: /usr/local/lib/libabsl_cord.a
route_plan: /usr/local/lib/libabsl_str_format_internal.a
route_plan: /usr/local/lib/libabsl_synchronization.a
route_plan: /usr/local/lib/libabsl_stacktrace.a
route_plan: /usr/local/lib/libabsl_symbolize.a
route_plan: /usr/local/lib/libabsl_debugging_internal.a
route_plan: /usr/local/lib/libabsl_demangle_internal.a
route_plan: /usr/local/lib/libabsl_graphcycles_internal.a
route_plan: /usr/local/lib/libabsl_malloc_internal.a
route_plan: /usr/local/lib/libabsl_time.a
route_plan: /usr/local/lib/libabsl_strings.a
route_plan: /usr/local/lib/libabsl_throw_delegate.a
route_plan: /usr/local/lib/libabsl_strings_internal.a
route_plan: /usr/local/lib/libabsl_base.a
route_plan: /usr/local/lib/libabsl_spinlock_wait.a
route_plan: /usr/local/lib/libabsl_int128.a
route_plan: /usr/local/lib/libabsl_civil_time.a
route_plan: /usr/local/lib/libabsl_time_zone.a
route_plan: /usr/local/lib/libabsl_bad_optional_access.a
route_plan: /usr/local/lib/libabsl_raw_logging_internal.a
route_plan: /usr/local/lib/libabsl_log_severity.a
route_plan: /usr/local/lib/libssl.a
route_plan: /usr/local/lib/libcrypto.a
route_plan: /usr/local/lib/libgrpc++_reflection.a
route_plan: /usr/local/lib/libgrpc++.a
route_plan: /usr/local/lib/libprotobuf.a
route_plan: /usr/local/lib/libgrpc.a
route_plan: /usr/local/lib/libz.a
route_plan: /usr/local/lib/libcares.a
route_plan: /usr/local/lib/libaddress_sorting.a
route_plan: /usr/local/lib/libre2.a
route_plan: /usr/local/lib/libupb.a
route_plan: /usr/local/lib/libabsl_hash.a
route_plan: /usr/local/lib/libabsl_city.a
route_plan: /usr/local/lib/libabsl_raw_hash_set.a
route_plan: /usr/local/lib/libabsl_hashtablez_sampler.a
route_plan: /usr/local/lib/libabsl_exponential_biased.a
route_plan: /usr/local/lib/libabsl_statusor.a
route_plan: /usr/local/lib/libabsl_bad_variant_access.a
route_plan: /usr/local/lib/libgpr.a
route_plan: /usr/local/lib/libabsl_status.a
route_plan: /usr/local/lib/libabsl_cord.a
route_plan: /usr/local/lib/libabsl_str_format_internal.a
route_plan: /usr/local/lib/libabsl_synchronization.a
route_plan: /usr/local/lib/libabsl_stacktrace.a
route_plan: /usr/local/lib/libabsl_symbolize.a
route_plan: /usr/local/lib/libabsl_debugging_internal.a
route_plan: /usr/local/lib/libabsl_demangle_internal.a
route_plan: /usr/local/lib/libabsl_graphcycles_internal.a
route_plan: /usr/local/lib/libabsl_malloc_internal.a
route_plan: /usr/local/lib/libabsl_time.a
route_plan: /usr/local/lib/libabsl_strings.a
route_plan: /usr/local/lib/libabsl_throw_delegate.a
route_plan: /usr/local/lib/libabsl_strings_internal.a
route_plan: /usr/local/lib/libabsl_base.a
route_plan: /usr/local/lib/libabsl_spinlock_wait.a
route_plan: /usr/local/lib/libabsl_int128.a
route_plan: /usr/local/lib/libabsl_civil_time.a
route_plan: /usr/local/lib/libabsl_time_zone.a
route_plan: /usr/local/lib/libabsl_bad_optional_access.a
route_plan: /usr/local/lib/libabsl_raw_logging_internal.a
route_plan: /usr/local/lib/libabsl_log_severity.a
route_plan: /usr/local/lib/libssl.a
route_plan: /usr/local/lib/libcrypto.a
route_plan: JobManagement/grpc_files/jobmanagement_ordermanagement/libjobmanagement_ordermanagement.a
route_plan: CMakeFiles/route_plan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/source/simulator_server_track/route_plan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable route_plan"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/route_plan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/route_plan.dir/build: route_plan

.PHONY : CMakeFiles/route_plan.dir/build

CMakeFiles/route_plan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/route_plan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/route_plan.dir/clean

CMakeFiles/route_plan.dir/depend:
	cd /root/source/simulator_server_track/route_plan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/source/simulator_server_track/route_plan /root/source/simulator_server_track/route_plan /root/source/simulator_server_track/route_plan/build /root/source/simulator_server_track/route_plan/build /root/source/simulator_server_track/route_plan/build/CMakeFiles/route_plan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/route_plan.dir/depend
