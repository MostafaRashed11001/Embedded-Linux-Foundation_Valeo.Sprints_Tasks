# Specify the minimum required version of CMake.
cmake_minimum_required(VERSION 3.1...3.27)

# Declare the project and its version.
project(Math_App VERSION 1.0 LANGUAGES CXX)

add_library(IPC_App ../IPC_LIBRARY/IPC_Library.cpp)
add_library(Utils_App ../Utils/Utils.cpp)

# Define an executable named "Math_App" based on MathApp.cpp.
add_executable(Math_App MathApp.cpp)

# Link the required libraries to the "Math_App" executable.
target_link_libraries(Math_App IPC_App)
target_link_libraries(Math_App Utils_App)

# Install the "Math_App" executable.
install(TARGETS Math_App)
