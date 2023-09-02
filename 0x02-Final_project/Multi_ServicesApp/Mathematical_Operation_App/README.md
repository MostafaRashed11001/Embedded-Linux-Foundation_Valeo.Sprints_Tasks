# Mathematical Operation Application

The Mathematical Operation Application is a simple command-line tool designed to perform basic mathematical operations (addition, subtraction, multiplication, and division) on two numbers. It allows users to execute these operations and logs the results using a message queue for further processing by the Logger Daemon. This documentation provides an overview of the application's functionality, source code structure, and usage.

## Dependencies

1. `IPC Library`:  The application utilizes the IPC Library for communication with the Logger Daemon via message queues.

2. `Utils Library`:  It uses the Utils Library for utility functions and logging.

## Initialization

1. The application begins by creating a `MessageQueueSender` instance to send log messages to the Logger Daemon.

2. It connects to the message queue and sends the application name and queue name to the Logger Daemon for identification and configuration.

## Main Functionality

1. The main function of the application allows users to perform mathematical operations through command-line arguments.

2. Supported operations:
   - Addition (`Sum`)
   - Subtraction (`Sub`)
   - Multiplication (`Mul`)
   - Division (`Div`)
3. The main steps include:
   - Parsing the command-line arguments to determine the operation to be performed and the numbers to operate on.
   - Performing the requested operation and calculating the result.
   - Constructing a log message with the operation details and result.
   - Sending the log message to the Logger Daemon using the `MessageQueueSender`.

## Command-Line Usage

1. Users can execute the Mathematical Operation Application by providing appropriate command-line arguments:
    ```sh
        ./Math_App [Operation] [Number1] [Number2]
    ```
    - `Operation`: Specify the operation to be performed (`Sum`, `Sub`, `Mul`, or `Div`).
    - `Number1` and `Number2`: Provide the two numbers on which the operation should be performed.

2. Additionally, users can request help using the `--help` flag to display the application's manual:
    ```sh
        ./Math_App --help
    ```
## User Manual

The user manual for the Mathematical Operation Application is stored in the `MathAppManual.txt` file. Users can access this manual by running the application with the `--help` flag. The manual provides guidance on how to use the application and its supported operations.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)