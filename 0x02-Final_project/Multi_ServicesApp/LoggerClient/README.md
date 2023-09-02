# Logger Receiver Application 

The Logger Receiver Application is designed to run on your own machine and receive logs sent over Ethernet from other applications, such as the Daemon Logger. This application acts as a log collector, receiving logs via TCP/IP and displaying them on the console. This documentation covers the key components and usage of the Logger Receiver Application.

## Application Functionality

The Logger Receiver Application performs the following key functions:

1. `Socket Creation`: Creates a socket for communication with the log sender.

2. `Connection Establishment`: Connects to the server (log sender) using the specified IP address and port.

3. `Continuous Log Reception`: Continuously receives log messages from the server.

4. `Log Display`: Displays received log messages on the console.

## Configuration

1. `IP Address`: The application is configured with a predefined IP address (`IP_Server`) to connect to the log sender. You should specify the correct IP address in the configuration.

2. `Port`: The application connects to the server using a specified port (currently set to `51000`). Ensure that the port is correctly configured.

## Usage

1. `Include Header File`: Include the necessary header file, `Socket_Client.h`, in your application to use the Logger Receiver Application.

2. `Create Socket`: Call the `CreateSocket` function to create a socket for communication.

3. `Connect to Server`: Use the `connect` system call to establish a connection to the server (log sender) with the specified IP address and port.

4. `Receive and Display Logs`: Continuously receive and display log messages from the server. Logs are received in the `Buffer` and displayed on the console.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)