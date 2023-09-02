# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.1...3.27)

# Define the project and its characteristics.
project(Multi_ServicesaApp VERSION 1.0 LANGUAGES CXX)

# Add subdirectories for different components of the project
add_subdirectory(Utils)
link_libraries(Utils)
add_subdirectory(Daemon)
add_subdirectory(IPC_LIBRARY)
add_subdirectory(Socket)
add_subdirectory(Main_Service)
add_subdirectory(Mathematical_Operation_App)
