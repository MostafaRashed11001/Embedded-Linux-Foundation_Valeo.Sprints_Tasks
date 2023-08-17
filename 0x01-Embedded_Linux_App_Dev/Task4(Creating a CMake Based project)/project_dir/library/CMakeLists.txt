# Create a static library named WriteInFile_lib from the source file WriteInFile.cpp
add_library(WriteInFile_lib STATIC WriteInFile.cpp)

# Make the include directories from the parent directory's 'include' available to users of WriteInFile_lib
# This allows users to include headers using "#include <WriteInFile.h>" without specifying the full path
target_include_directories(WriteInFile_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
