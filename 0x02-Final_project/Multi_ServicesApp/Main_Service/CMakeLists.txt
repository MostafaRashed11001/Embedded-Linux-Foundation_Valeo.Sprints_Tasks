# Specify the minimum required version of CMake.
cmake_minimum_required(VERSION 3.1...3.27)

# Declare the project and its version.
project(Main_Service VERSION 1.0 LANGUAGES CXX)

add_library(IPC_Main ../IPC_LIBRARY/IPC_Library.cpp)
add_library(Utils_Main ../Utils/Utils.cpp)
add_library(Daemon_Main ../Daemon/daemon.cpp)
add_library(Socket_Main ../Socket/Socket_Server.cpp)

# Define an executable named "Main_Service" based on Logger_Daemon.cpp.
add_executable(Main_Service Logger_Daemon.cpp)

# Link the required libraries to the "Main_Service" executable.
target_link_libraries(Main_Service IPC_Main)
target_link_libraries(Main_Service Daemon_Main)
target_link_libraries(Main_Service Socket_Main)
target_link_libraries(Main_Service Utils_Main)

# Install the "Main_Service" executable.
install(TARGETS Main_Service)
