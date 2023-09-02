# Multi Services Application

This project is a comprehensive system designed to manage and log various applications' activities and messages efficiently. It includes several components such as a Logger Daemon, Mathematical Operation Application, IPC Library, Socket Server, and more. This documentation provides an overview of the project, its file structure, dependencies, and usage instructions for each component.

## Project Structure

Here is the directory structure of the project:

``` sh
   .
├── Boost_Logger
│   ├── Logger.cpp
│   └── Logger.h
├── CMakeLists.txt
├── Daemon
│   ├── CMakeLists.txt
│   ├── README.md
│   ├── daemon.cpp
│   └── daemon.h
├── IPC_LIBRARY
│   ├── CMakeLists.txt
│   ├── IPC_Library.cpp
│   ├── IPC_Library.h
│   └── README.md
├── JSON
│   └── Logger_config.json
├── LoggerClient
│   ├── README.md
│   ├── Socket_Client
│   ├── Socket_Client.cpp
│   └── Socket_Client.h
├── Main_Service
│   ├── CMakeLists.txt
│   ├── Logger_Daemon.cpp
│   └── README.md
├── Mathematical_Operation_App
│   ├── CMakeLists.txt
│   ├── MathApp.cpp
│   ├── MathApp.h
│   ├── MathAppManual.txt
│   └── README.md
├── README.md
├── Socket
│   ├── CMakeLists.txt
│   ├── README.md
│   ├── Socket_Server.cpp
│   └── Socket_Server.h
├── SysD
│   └── LoggerDaemon.service
└── Utils
    ├── CMakeLists.txt
    ├── README.md
    ├── Utils.cpp
    └── Utils.h

```
## Components

1. Logger Daemon : The Logger Daemon is a central logging service that receives log messages from various applications and stores them in log files. It uses the Boost C++ Library for logging.

   - `Initialization` : The Logger Daemon is initialized as a system service using systemd. Configuration is read from the Logger_config.json file.

   - `Logging` : It receives log messages via IPC from other applications, processes them, and stores them in log files.

   - `Usage` : Ensure the Logger Daemon service is running, and configure the applications to send log messages to it.

2. Mathematical Operation Application : The Mathematical Operation Application is a command-line tool for performing basic mathematical operations (addition, subtraction, multiplication, division) on two numbers.

   - `Usage` : Execute the application with appropriate command-line arguments to perform mathematical operations. Refer to the user manual in `MathAppManual.txt` for details.

3. IPC Library : The IPC Library provides inter-process communication capabilities used by various components to communicate with the Logger Daemon.

4. Socket Server : The Socket Server component provides a server that accepts socket connections and forwards received messages to the Logger Daemon.

5. Boost Logger : The Boost Logger component provides a shared library for logging messages in a flexible and efficient way.

6. Utils Library : The Utils Library contains utility functions used across various components, including logging functions.

7. Logger Client : The Logger Client is a client application that connects to the Logger Daemon via sockets and sends log messages.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27) : Build automation tool used to configure, build, and install the project.
- C++ Compiler (e.g., g++)
- Boost C++ Libraries : Used for efficient and flexible logging in the Logger Daemon and other components.
- nlohmann/json Library : Used for parsing and managing configuration files.
- SysD : Systemd service manager for managing system services (used for the Logger Daemon service).

## Building and Running

1. Clone the repository to your local machine:
   ```sh
   git clone https://github.com/MostafaRashed11001/Embedded-Linux-Foundation_Valeo.Sprints_Tasks.git
   ```

2. Navigate to the repository's directory:
   ```sh
   cd 0x02-Final_project/Multi_ServicesApp
   ```

3. Copy `Logger_config.json` to `/etc/systemd/` && `LoggerDaemon.service` to `/etc/systemd/system/`.

4. Edit the `Logger_config.json` file with your configuration settings.

5. Run the following commands to build the project and tests:
   ```sh
   cmake -S . -B ./build -DCMAKE_INSTALL_PREFIX=./build/

   cmake --build build --target install
   ```

6. Run the following commands to make service in active mode and don't forget `chmod`:
   ```sh
   sudo systemctl enable LoggerDaemon.service

   sudo systemctl start LoggerDaemon.service

   sudo systemctl status LoggerDaemon.service
   ```

7. Configure the IP address for the Raspberry Pi 4 in the `Socket_Client.h` file.

8. Compilation and Execution for `Socket_Client.cpp` :
   ```sh
   g++ LoggerClient/Socket_Client

   ./LoggerClient/Socket_Client
   ```

9. Execution for `Math_App` in rpi4 :
   ```sh
      cd build/bin/

      ./Math_App [Operation] [Number1] [Number2]
   ```