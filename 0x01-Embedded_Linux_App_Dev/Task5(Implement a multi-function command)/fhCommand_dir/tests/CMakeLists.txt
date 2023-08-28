#Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.14)

# Define the project for the tests
project(FileHandlerTests)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 14)

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
add_library(Logger ../logger/logger.cpp)

# Link the Logger library to required Boost libraries and pthread
target_link_libraries(Logger ${Boost_LIBRARIES} pthread)

# Find the GTest package
find_package(GTest REQUIRED)

# Enable testing for the project
enable_testing()

# Define source files
set(SRC_FILE_FH ../src/fh/SrcFileHandler.cpp)
set(SRC_TEST_FH FileHandlerTest.cpp)

set(SRC_FILE_REQ ../src/Requester/SrcRequester.cpp)
set(SRC_TEST_REQ RequesterTest.cpp)

# Create an executable target for FileHandlerTests using the source files
add_executable(FileHandlerTests ${SRC_FILE_FH} ${SRC_TEST_FH})

# Link the FileHandlerTests executable to GTest libraries and Logger
target_link_libraries(FileHandlerTests GTest::gtest GTest::gtest_main)
target_link_libraries(FileHandlerTests Logger)

# Create an executable target for RequesterTests using the source files
add_executable(RequesterTests ${SRC_FILE_REQ} ${SRC_TEST_REQ})

# Link the RequesterTests executable to GTest libraries and Logger
target_link_libraries(RequesterTests GTest::gtest GTest::gtest_main)
target_link_libraries(RequesterTests Logger)

# Include GoogleTest's CMake module for test discovery
include(GoogleTest)

# Discover and run tests using GoogleTest
gtest_discover_tests(${PROJECT_NAME})

# Install the test executables
install(TARGETS FileHandlerTests)
install(TARGETS RequesterTests)