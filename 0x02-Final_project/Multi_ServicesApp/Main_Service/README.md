# Logger Daemon

The Logger Daemon is a crucial component of the system responsible for receiving log messages from various applications, filtering and processing these messages, and logging them based on the configuration provided in a JSON file. This documentation provides an overview of the Logger Daemon's functionality, source code structure, and usage.

## Dependencies

1. `IPC Library`: The Logger Daemon uses the IPC Library to receive log messages and application names from other components.

2. `Daemon Library`: It utilizes the Daemon library to become a daemon process.

3. `Socket Server Library`: The Socket Server library is used to establish a socket connection for potential communication with external monitoring tools.

4. `Utils Library`: This library provides utility functions for logging and configuration handling.

5. `nlohmann/json Library`: Used for parsing and handling JSON configuration files.
    - `Logger_config.json` : A JSON configuration file specifying the mapping between application names, message queue names, and log levels.


## Main Loop

1. The Logger Daemon enters a continuous loop where it receives log messages and related information through the IPC Library.

2. The main steps within the loop are as follows:
   - Receive the application name from the message queue.
   - Check if the received application name is configured in the JSON configuration.
   - If configured, receive the associated queue name.
   - Validate that the received queue name matches the configured queue name for the application.
   - If valid, receive the log message.
   - Log the received log message with the specified log level.
   - If the application name, queue name, or log level is not configured or does not match, log a warning message.

# Usage

1. The Logger Daemon uses the Utils library to log messages with specific log levels. These log messages are associated with component types, including "LoggerDaemon," "IPC," and "SocketServer."

2. The Logger Daemon creates a socket connection to allow communication with external monitoring tools or logging systems. This feature can be extended for remote log retrieval or real-time monitoring.

3. The Logger Daemon is intended to run continuously in the background, processing log messages from various applications and logging them based on the provided configuration.

4. `Error Handling`: Handle exceptions of type `IPCException` that may be thrown during message queue operations.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)
- Boost Library
- nlohmann/json Library