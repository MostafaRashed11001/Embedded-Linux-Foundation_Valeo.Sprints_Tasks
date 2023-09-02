# Utils Library

The Utils library provides essential utility functions and constants that are used across various components of the system. These utilities include logging functions and constants for specifying log levels and component types, as well as a function to log messages and send them through a socket connection.

## Constants

1. `Log Levels`:
   - `TRACE`  : Log level for tracing.
   - `DEBUG`  : Log level for debugging.
   - `INFO`   : Log level for informational messages.
   - `WARNING`: Log level for warning messages.
   - `ERROR`  : Log level for error messages.
   - `FATAL`  : Log level for fatal error messages.

2. `Log Prefixes`:
   - `MathApp`: Prefix for messages related to the mathematical operations application.
   - `LoggerDaemon`: Prefix for messages related to the Logger Daemon application.
   - `IPC_LIB`:  Prefix for messages related to the IPC Library.
   - `SocketServer`: Prefix for messages related to the Socket Server component.

3. `Component Types`:
   - `Math`: Identifier for the mathematical operations application.
   - `LogDaemon`:  Identifier for the Logger Daemon application.
   - `IPC`:  Identifier for the IPC Library.
   - `Socket`: Identifier for the Socket Server component.

## Function `ClinetLogger`

1. `EDescription` : Logs messages with specific log levels and associates them with component types. Additionally, it sends the logged messages through a socket connection to a client.

2. `Parameters`:
   - `log`(std::string): The log message to be logged and sent.
   - `TypeLog`(int): The log level, one of `TRACE`, `DEBUG`, `INFO`, `WARNING`, `ERROR`, or `FATAL`.
   - `TypeFile`(int): The component type, one of `Math`, `LogDaemon`, `IPC`, or `Socket`.
   - `Example` : `ClinetLogger("This is an informational message.", INFO, Math);`

# Usage

The Utils library serves as a crucial utility for the overall system, ensuring that log messages are appropriately categorized, logged with the correct severity levels, and sent to the designated client component for monitoring or further processing. It enhances the maintainability and reliability of the system's logging capabilities.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)