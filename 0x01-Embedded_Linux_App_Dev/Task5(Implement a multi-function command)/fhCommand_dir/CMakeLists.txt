# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.1...3.27)

# Define the project and its characteristics.
project(FHCommandProject VERSION 1.0 LANGUAGES CXX)

# Add subdirectories
add_subdirectory(logger)
add_subdirectory(src/fh)
add_subdirectory(src/Requester)
add_subdirectory(tests)