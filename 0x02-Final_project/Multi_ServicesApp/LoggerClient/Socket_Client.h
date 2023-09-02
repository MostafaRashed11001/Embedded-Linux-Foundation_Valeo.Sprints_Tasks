#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#define BufferSize 4096  // Define the buffer size for receiving data.

#define IP_Server  "192.168.106.183"              // if using rpi4 -> "rpi4_ip" for ex: "192.168.106.183"      for S.W ->"127.0.0.1"

// Function declaration for creating a socket.
bool CreateSocket (void);


#endif /* SOCKET_CLIENT_H */