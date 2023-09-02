#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#define W_Build    true                    // if using rpi4   -> true    , if S.M        -> false
#define SysD       false                   // if run as SysD -> false    , if run S.M -> true

// Declare functions for creating, connecting, and sending data over a socket

// Function to create a socket and bind it to an address
bool CreateSocket(void);

// Function to listen for incoming connections and accept a client connection
bool ConnectSocket(void);

// Function to send a message over the connected socket
bool SendSocketMassage(std::string Massage);

#endif /* SOCKET_SERVER_H */
