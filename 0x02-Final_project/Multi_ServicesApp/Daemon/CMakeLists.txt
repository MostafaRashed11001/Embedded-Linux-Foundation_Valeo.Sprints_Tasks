# Define a static library named "Daemon" based on the daemon.cpp source file.
add_library(Daemon daemon.cpp)

add_library(Utils_Daemon ../Utils/Utils.cpp)
target_link_libraries(Daemon Utils_Daemon)
