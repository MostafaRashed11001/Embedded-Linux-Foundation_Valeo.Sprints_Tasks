# Set the minimum required version of CMake for this project.
# The specified version range should be between 3.10 and 3.27.
cmake_minimum_required(VERSION 3.1...3.27)

# Define the project and its characteristics.
# PROJECT_DIR is the project name, VERSION is the project version, and LANGUAGES sets the programming language(s).
project(PROJECT_DIR VERSION 1.0 LANGUAGES CXX)

# Include the subdirectories for building the 'library' and 'src' components.
add_subdirectory(library)
add_subdirectory(src)

# Link the 'WriteInFile_lib' library to the 'FinalTarget' executable.
# This connects the library's functionality with the executable.
target_link_libraries(FinalTarget PRIVATE WriteInFile_lib)

# Install the 'FinalTarget' executable during the installation process.
# This makes the executable available on the user's system after building.
install(TARGETS FinalTarget)