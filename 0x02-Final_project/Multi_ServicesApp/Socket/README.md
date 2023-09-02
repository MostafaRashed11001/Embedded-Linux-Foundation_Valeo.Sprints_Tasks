# Socket Server

The Socket Server application is designed to create a server socket, listen for incoming connections, and send messages to connected clients over TCP/IP. This documentation provides an overview of the application's components, functionality, and usage.

# Application Components

The Socket Server application consists of the following key components:

1. `Socket Creation`: This component initializes a socket for communication.

2. `Connection Establishment`: The application listens for incoming connections and accepts client connections.

3. `Message Sending`: It provides the functionality to send messages to connected clients.

4. `Error Handling`: The application handles various socket-related errors and logs them.

# Configuration

The Socket Server application can be configured based on your requirements:

1. `Server Address`: The server is bound to the address `0.0.0.0`, which means it listens on all available network interfaces. You can change this address if needed.

2. `Port Number`: The server listens on port `51000` by default. You can modify the port number according to your requirements.

2. `Build Configuration`: The `W_Build` flag determines the build configuration. Set it to `true` for Raspberry Pi 4 (rpi4) or `false` for software (S.W) configuration.

# Usage

1. `Include Header File`: Include the `Socket_Server.h` header file in your application to use the Socket Server components.

2. `Create Socket`: Call the `CreateSocket` function to create and initialize the server socket.

3. `Listen and Accept Connections`: Use the `ConnectSocket` function to listen for incoming connections and accept client connections.

4. `Send Messages`: Use the `SendSocketMassage` function to send messages to connected clients.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)