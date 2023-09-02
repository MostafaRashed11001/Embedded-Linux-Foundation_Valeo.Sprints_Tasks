# Define a static library named "IPC" based on the IPC_Library.cpp source file.
add_library(IPC IPC_Library.cpp)

add_library(Utils_IPC ../Utils/Utils.cpp)
target_link_libraries(IPC Utils_IPC)
