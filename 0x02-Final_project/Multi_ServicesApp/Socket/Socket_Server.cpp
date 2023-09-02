#include <string.h>
#include "../Utils/Utils.h"
#include "Socket_Server.h"
#include <errno.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

// Structure describing an Internet socket address for the server
sockaddr_in ServerAdd;

// Structure describing an Internet socket address for the connected client
sockaddr_in ClientAdd;

// Socket descriptor for the server socket
int SocketDescriptor;

// Socket descriptor for the connected client socket
int ClientSocketDescriptor;

// Buffer to store the hostname or IP address of the connected client
char host[NI_MAXHOST] = {0};

// Buffer to store the service (port) information of the connected client
char service[NI_MAXSERV] = {0};

// Function to create and bind a socket
bool CreateSocket (void) {
    
    bool StatusReturn = true;
    
    // Create a socket with AF_INET domain (IPv4), SOCK_STREAM type (TCP), and protocol 0 (default)
    SocketDescriptor = socket(AF_INET,SOCK_STREAM,0);

    // Check if socket creation was successful
    if (SocketDescriptor == -1){
        ClinetLogger("Could not create socket !!  " + std::string(strerror(errno)) + "\n", ERROR, Socket);
        StatusReturn = false;
    }

    // Set up server address structure
    ServerAdd.sin_family = AF_INET;     // Address family (IPv4)
    ServerAdd.sin_port = htons(51000);  // Port number in network byte order (htons)
# if W_Build
    ServerAdd.sin_addr.s_addr = INADDR_ANY;
# endif
    // Convert "0.0.0.0" to network byte order and set it as the server IP address
    int Status = inet_pton(AF_INET,"0.0.0.0",&ServerAdd.sin_addr);
    
    // Check the result of inet_pton
    if (Status == 0) {
        ClinetLogger("src does not contain a character string representing a valid network address in the specified address family.\n", WARNING, Socket);
    } else if (Status == -1) {
        ClinetLogger("Error in converting address.  " + std::string(strerror(errno)) + "\n", ERROR, Socket);
        StatusReturn = false;
    }
    /*
        When a socket is created with socket(), it exists in a name
        space (address family) but has no address assigned to it.  
        bind() assigns the address specified by addr to the socket referred to
        by the file descriptor sockfd.  addrlen specifies the size, in
        bytes, of the address structure pointed to by addr.
        Traditionally, this operation is called “assigning a name to a
        socket”.
    */
    if (bind(SocketDescriptor , (sockaddr*)&ServerAdd , sizeof(ServerAdd)) == -1){

        ClinetLogger("Error in converting address.  " + std::string(strerror(errno)) + "\n", ERROR, Socket);
        StatusReturn = false;
    }
    return StatusReturn;
}

// Function to listen for incoming connections and accept a client connection
bool ConnectSocket (void) {
    bool Status = true;
    /*
        listen() marks the socket referred to by sockfd as a passive
        socket, that is, as a socket that will be used to accept incoming
        connection requests using accept(2).

        The sockfd argument is a file descriptor that refers to a socket
        of type SOCK_STREAM or SOCK_SEQPACKET.
    */
    if (listen(SocketDescriptor , SOMAXCONN) == -1) {
        ClinetLogger("Error in listen!!  " + std::string(strerror(errno)) + "\n", ERROR, Socket);
        Status = false;
    }

    socklen_t clientSize = sizeof(ClientAdd);
    /*
        The accept() system call is used with connection-based socket
        types (SOCK_STREAM, SOCK_SEQPACKET).  It extracts the first
        connection request on the queue of pending connections for the
        listening socket, sockfd, creates a new connected socket, and
        returns a new file descriptor referring to that socket.  The
        newly created socket is not in the listening state.  The original
        socket sockfd is unaffected by this call.
    */
    ClientSocketDescriptor = accept(SocketDescriptor , (sockaddr *)&ClientAdd , &clientSize);

    if (ClientSocketDescriptor == -1){
        ClinetLogger("Error in accepting connection  " + std::string(strerror(errno)) + "\n", ERROR, Socket);
        Status = false;
    }
    return Status;
}

// Function to send a message to the connected client socket
bool SendSocketMassage (std::string Massage) {

    bool Status = true;
    /*
        The getnameinfo() function is the inverse of getaddrinfo(): it
        converts a socket address to a corresponding host and service, in
        a protocol-independent manner.
    */
    if (getnameinfo((sockaddr*)&ClientAdd , sizeof(ClientAdd) , host , NI_MAXHOST, service, NI_MAXSERV, 0) != 0) {
        
        // If getnameinfo fails, manually extract and log client address and port
        if (inet_ntop(AF_INET, &ClientAdd.sin_addr, host , NI_MAXHOST) == nullptr) {
            Status = false;
        }
    }

    // Send the message to the connected client socket
    if (send(ClientSocketDescriptor , Massage.c_str() , Massage.length() , 0 ) == -1) {
        Status = false;
    }
/*
    if (Status == true) {
        std::cout << "\nSend Success : \nHost : " << host << "\nService : " << service;
    }
*/
    return Status;
}