# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.1...3.27)

# Define the project and its characteristics.
project(FileHandler VERSION 1.0 LANGUAGES CXX)

# Configure Boost settings
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

# Find the required Boost libraries
find_package(Boost 1.80 COMPONENTS log log_setup system thread REQUIRED)

# Include Boost header directories
include_directories(${Boost_INCLUDE_DIR})

# Link to Boost library directories
link_directories(${Boost_LIBRARY_DIRS})

# Display Boost-related information
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")


# Create a library target for Logger using logger.cpp
add_library(Logger_FH ../../logger/logger.cpp)

# Link the Logger library to required Boost libraries and pthread
target_link_libraries(Logger_FH ${Boost_LIBRARIES} pthread)


# Create an executable target for FileHandlerApp using FileHandler.cpp
add_executable(FileHandlerApp FileHandler.cpp)


# Link the FileHandlerApp executable to the Logger library
target_link_libraries(FileHandlerApp Logger_FH)

install(TARGETS FileHandlerApp)