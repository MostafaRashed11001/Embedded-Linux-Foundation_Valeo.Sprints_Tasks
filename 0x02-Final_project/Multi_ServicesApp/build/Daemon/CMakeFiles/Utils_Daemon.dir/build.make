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
CMAKE_SOURCE_DIR = /home/mostafa_rashed/Multi_ServicesApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mostafa_rashed/Multi_ServicesApp/build

# Include any dependencies generated for this target.
include Daemon/CMakeFiles/Utils_Daemon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Daemon/CMakeFiles/Utils_Daemon.dir/compiler_depend.make

# Include the progress variables for this target.
include Daemon/CMakeFiles/Utils_Daemon.dir/progress.make

# Include the compile flags for this target's objects.
include Daemon/CMakeFiles/Utils_Daemon.dir/flags.make

Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o: Daemon/CMakeFiles/Utils_Daemon.dir/flags.make
Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o: ../Utils/Utils.cpp
Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o: Daemon/CMakeFiles/Utils_Daemon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mostafa_rashed/Multi_ServicesApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o"
	cd /home/mostafa_rashed/Multi_ServicesApp/build/Daemon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o -MF CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o.d -o CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o -c /home/mostafa_rashed/Multi_ServicesApp/Utils/Utils.cpp

Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.i"
	cd /home/mostafa_rashed/Multi_ServicesApp/build/Daemon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mostafa_rashed/Multi_ServicesApp/Utils/Utils.cpp > CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.i

Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.s"
	cd /home/mostafa_rashed/Multi_ServicesApp/build/Daemon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mostafa_rashed/Multi_ServicesApp/Utils/Utils.cpp -o CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.s

# Object files for target Utils_Daemon
Utils_Daemon_OBJECTS = \
"CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o"

# External object files for target Utils_Daemon
Utils_Daemon_EXTERNAL_OBJECTS =

Daemon/libUtils_Daemon.a: Daemon/CMakeFiles/Utils_Daemon.dir/__/Utils/Utils.cpp.o
Daemon/libUtils_Daemon.a: Daemon/CMakeFiles/Utils_Daemon.dir/build.make
Daemon/libUtils_Daemon.a: Daemon/CMakeFiles/Utils_Daemon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mostafa_rashed/Multi_ServicesApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUtils_Daemon.a"
	cd /home/mostafa_rashed/Multi_ServicesApp/build/Daemon && $(CMAKE_COMMAND) -P CMakeFiles/Utils_Daemon.dir/cmake_clean_target.cmake
	cd /home/mostafa_rashed/Multi_ServicesApp/build/Daemon && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Utils_Daemon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Daemon/CMakeFiles/Utils_Daemon.dir/build: Daemon/libUtils_Daemon.a
.PHONY : Daemon/CMakeFiles/Utils_Daemon.dir/build

Daemon/CMakeFiles/Utils_Daemon.dir/clean:
	cd /home/mostafa_rashed/Multi_ServicesApp/build/Daemon && $(CMAKE_COMMAND) -P CMakeFiles/Utils_Daemon.dir/cmake_clean.cmake
.PHONY : Daemon/CMakeFiles/Utils_Daemon.dir/clean

Daemon/CMakeFiles/Utils_Daemon.dir/depend:
	cd /home/mostafa_rashed/Multi_ServicesApp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mostafa_rashed/Multi_ServicesApp /home/mostafa_rashed/Multi_ServicesApp/Daemon /home/mostafa_rashed/Multi_ServicesApp/build /home/mostafa_rashed/Multi_ServicesApp/build/Daemon /home/mostafa_rashed/Multi_ServicesApp/build/Daemon/CMakeFiles/Utils_Daemon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Daemon/CMakeFiles/Utils_Daemon.dir/depend

