# brief: CMake configuration file for building the 'logger' library.

# Add the 'logger' library target using the source file 'logger.cpp'
add_library(logger logger.cpp)

# Configure the include directories for the 'logger' library
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})