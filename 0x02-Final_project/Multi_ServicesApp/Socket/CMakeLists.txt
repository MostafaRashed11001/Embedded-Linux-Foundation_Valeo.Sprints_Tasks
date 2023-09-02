# Add a library target named "Socket" and link it to the source file "Socket_Server.cpp"
add_library(Socket Socket_Server.cpp)

add_library(Utils_Socket ../Utils/Utils.cpp)
target_link_libraries(Socket Utils_Socket)
