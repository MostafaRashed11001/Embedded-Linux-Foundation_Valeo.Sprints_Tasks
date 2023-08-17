# Create an executable named 'FinalTarget' from the source files 'main.cpp' and 'Print.cpp'.
add_executable(FinalTarget main.cpp Print.cpp)

# Specify the include directories for the 'FinalTarget' executable.
# This ensures that headers from the parent directory's 'include' are available for compilation.
target_include_directories(FinalTarget PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)