# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mostafa_rashed/fhCommand_dir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mostafa_rashed/fhCommand_dir/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/RequesterTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/RequesterTests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/RequesterTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/RequesterTests.dir/flags.make

tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o: tests/CMakeFiles/RequesterTests.dir/flags.make
tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o: ../src/Requester/SrcRequester.cpp
tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o: tests/CMakeFiles/RequesterTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mostafa_rashed/fhCommand_dir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o -MF CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o.d -o CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o -c /home/mostafa_rashed/fhCommand_dir/src/Requester/SrcRequester.cpp

tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.i"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mostafa_rashed/fhCommand_dir/src/Requester/SrcRequester.cpp > CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.i

tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.s"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mostafa_rashed/fhCommand_dir/src/Requester/SrcRequester.cpp -o CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.s

tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o: tests/CMakeFiles/RequesterTests.dir/flags.make
tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o: ../tests/RequesterTest.cpp
tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o: tests/CMakeFiles/RequesterTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mostafa_rashed/fhCommand_dir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o -MF CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o.d -o CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o -c /home/mostafa_rashed/fhCommand_dir/tests/RequesterTest.cpp

tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RequesterTests.dir/RequesterTest.cpp.i"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mostafa_rashed/fhCommand_dir/tests/RequesterTest.cpp > CMakeFiles/RequesterTests.dir/RequesterTest.cpp.i

tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RequesterTests.dir/RequesterTest.cpp.s"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mostafa_rashed/fhCommand_dir/tests/RequesterTest.cpp -o CMakeFiles/RequesterTests.dir/RequesterTest.cpp.s

# Object files for target RequesterTests
RequesterTests_OBJECTS = \
"CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o" \
"CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o"

# External object files for target RequesterTests
RequesterTests_EXTERNAL_OBJECTS =

tests/RequesterTests: tests/CMakeFiles/RequesterTests.dir/__/src/Requester/SrcRequester.cpp.o
tests/RequesterTests: tests/CMakeFiles/RequesterTests.dir/RequesterTest.cpp.o
tests/RequesterTests: tests/CMakeFiles/RequesterTests.dir/build.make
tests/RequesterTests: /usr/local/lib/libgtest.a
tests/RequesterTests: /usr/local/lib/libgtest_main.a
tests/RequesterTests: tests/libLogger.a
tests/RequesterTests: /usr/local/lib/libgtest.a
tests/RequesterTests: /usr/lib/libboost_log_setup.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_log.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_chrono.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_filesystem.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_atomic.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_regex.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_system.so.1.80.0
tests/RequesterTests: /usr/lib/libboost_thread.so.1.80.0
tests/RequesterTests: tests/CMakeFiles/RequesterTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mostafa_rashed/fhCommand_dir/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable RequesterTests"
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RequesterTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/RequesterTests.dir/build: tests/RequesterTests
.PHONY : tests/CMakeFiles/RequesterTests.dir/build

tests/CMakeFiles/RequesterTests.dir/clean:
	cd /home/mostafa_rashed/fhCommand_dir/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/RequesterTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/RequesterTests.dir/clean

tests/CMakeFiles/RequesterTests.dir/depend:
	cd /home/mostafa_rashed/fhCommand_dir/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mostafa_rashed/fhCommand_dir /home/mostafa_rashed/fhCommand_dir/tests /home/mostafa_rashed/fhCommand_dir/build /home/mostafa_rashed/fhCommand_dir/build/tests /home/mostafa_rashed/fhCommand_dir/build/tests/CMakeFiles/RequesterTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/RequesterTests.dir/depend

