# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/mostafa_rashed-pi/Multi_ServicesApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4

# Include any dependencies generated for this target.
include Mathematical_Operation_App/CMakeFiles/Utils_App.dir/depend.make

# Include the progress variables for this target.
include Mathematical_Operation_App/CMakeFiles/Utils_App.dir/progress.make

# Include the compile flags for this target's objects.
include Mathematical_Operation_App/CMakeFiles/Utils_App.dir/flags.make

Mathematical_Operation_App/CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.o: Mathematical_Operation_App/CMakeFiles/Utils_App.dir/flags.make
Mathematical_Operation_App/CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.o: ../Utils/Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Mathematical_Operation_App/CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.o"
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.o -c /home/mostafa_rashed-pi/Multi_ServicesApp/Utils/Utils.cpp

Mathematical_Operation_App/CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.i"
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mostafa_rashed-pi/Multi_ServicesApp/Utils/Utils.cpp > CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.i

Mathematical_Operation_App/CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.s"
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mostafa_rashed-pi/Multi_ServicesApp/Utils/Utils.cpp -o CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.s

# Object files for target Utils_App
Utils_App_OBJECTS = \
"CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.o"

# External object files for target Utils_App
Utils_App_EXTERNAL_OBJECTS =

Mathematical_Operation_App/libUtils_App.a: Mathematical_Operation_App/CMakeFiles/Utils_App.dir/__/Utils/Utils.cpp.o
Mathematical_Operation_App/libUtils_App.a: Mathematical_Operation_App/CMakeFiles/Utils_App.dir/build.make
Mathematical_Operation_App/libUtils_App.a: Mathematical_Operation_App/CMakeFiles/Utils_App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUtils_App.a"
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App && $(CMAKE_COMMAND) -P CMakeFiles/Utils_App.dir/cmake_clean_target.cmake
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Utils_App.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Mathematical_Operation_App/CMakeFiles/Utils_App.dir/build: Mathematical_Operation_App/libUtils_App.a

.PHONY : Mathematical_Operation_App/CMakeFiles/Utils_App.dir/build

Mathematical_Operation_App/CMakeFiles/Utils_App.dir/clean:
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App && $(CMAKE_COMMAND) -P CMakeFiles/Utils_App.dir/cmake_clean.cmake
.PHONY : Mathematical_Operation_App/CMakeFiles/Utils_App.dir/clean

Mathematical_Operation_App/CMakeFiles/Utils_App.dir/depend:
	cd /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mostafa_rashed-pi/Multi_ServicesApp /home/mostafa_rashed-pi/Multi_ServicesApp/Mathematical_Operation_App /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4 /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App /home/mostafa_rashed-pi/Multi_ServicesApp/build_rpi4/Mathematical_Operation_App/CMakeFiles/Utils_App.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Mathematical_Operation_App/CMakeFiles/Utils_App.dir/depend

