cmake_minimum_required(VERSION 3.1...3.27)
project(Logger VERSION 1.0 LANGUAGES CXX)

# For rpi4
#set(CMAKE_CXX_COMPILER "/home/mostafa_rashed/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-g++")
#set(CMAKE_C_COMPILER "/home/mostafa_rashed/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-gcc")

# Find required Boost components
#find_package(Boost REQUIRED COMPONENTS log log_setup system thread)

# Include Boost headers and libraries
#include_directories("/home/mostafa_rashed/boost_1_80_0")
#link_directories("/home/mostafa_rashed/boost_1_80_0/stage/lib")


# For S.M 
# Set Boost options
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

# Find required Boost components
find_package(Boost 1.74 COMPONENTS log log_setup system thread REQUIRED)

# Include Boost headers and libraries
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")

# Add a library for Logger
add_library(Logger ../Boost_Logger/Logger.cpp)
target_link_libraries(Logger ${Boost_LIBRARIES} pthread)

# Add a library for the Socket server
add_library(socket ../Socket/Socket_Server.cpp)

# Add a library for Utils
add_library(Utils Utils.cpp)

# Link the Utils library with socket and Logger
target_link_libraries(Utils socket)
target_link_libraries(Utils Logger)
