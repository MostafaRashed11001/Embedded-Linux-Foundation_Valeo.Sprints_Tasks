#include "Socket_Client.h"            // Include the corresponding header file.

sockaddr_in ClientAdd;                // Structure to hold client address information.
int SocketDescriptor;                 // Socket descriptor for the client.
std::string IP_address = IP_Server; // IP address to connect to.
char Buffer[BufferSize] = {0};        // Buffer to store received data from the server.

// Main function for the client program.
int main() {

    // Create Socket
    if (CreateSocket () == false) {
        return -1;
    }
    //	Connect to the server on the socket
    int ConnectResult = connect(SocketDescriptor, (sockaddr*)&ClientAdd, sizeof(ClientAdd));
    if (ConnectResult == -1)
    {
        std::cout<<"Could not connect to  server !!"<< std::endl;
		return -1;
    }

    // Continuously receive and display data from the server.
    while (true)
    {
        int MassageReceivedSize = recv(SocketDescriptor, Buffer, BufferSize, 0);
        if (MassageReceivedSize  == -1)
        {
            std::cout << "There was an error getting response from server"<< std::endl;
        }
        else
        {
            std::cout << "Server send : " << std::string(Buffer, MassageReceivedSize+1) << std::endl;
        }
        sleep(4);
    }

    return 0;
}

// Function to create a socket.
bool CreateSocket (void) {
    bool StatusReturn = true;

    // Socket creation
    SocketDescriptor = socket(AF_INET,SOCK_STREAM,0);

    // Check Socket creation
    if (SocketDescriptor == -1){
        std::cout<<"Could not create socket !!"<<std::endl;
        StatusReturn = false;
    }

    // SocketInfo
    ClientAdd.sin_family = AF_INET;
    ClientAdd.sin_port = htons(51000);  // Server port to connect to.
    /*
        This function converts the character string src into a network
        address structure in the af address family, then copies the
        network address structure to dst.  The af argument must be either
        AF_INET or AF_INET6.  dst is written in network byte order.
    */
    int Status = inet_pton(AF_INET,IP_address.c_str(),&ClientAdd.sin_addr);
    if (Status == 0) {
        std::cout<<"src does not contain a character string representing a valid network address in the specified address family.\n";
    } else if (Status == -1) {
        StatusReturn = false;
    }

    return StatusReturn;
}