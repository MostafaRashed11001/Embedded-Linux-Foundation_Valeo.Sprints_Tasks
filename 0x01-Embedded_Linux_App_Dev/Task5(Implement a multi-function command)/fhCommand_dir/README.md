# File Handler Project

This project demonstrates file operations, shared memory, and semaphore usage through the implementation of the FileHandler and Requester components.

## Project Structure

Here is the directory structure of the project:

FileHandlerProject/
├── Result/
│   ├── DefaultFile
│   ├── GTest_Dir_Run/
│   ├── PipeChannel
├── src/
│   ├── fh/
│   └── Requester/
├── tests/
├── logger/
├── run_logs.txt
├── CMakeLists.txt
└── README.md


## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)
- Boost C++ Libraries
- Google Test Framework

## Building and Running

1. Clone the repository to your local machine:
   ```sh
   git clone https://github.com/MostafaRashed11001/Embedded-Linux-Foundation_Valeo.Sprints_Tasks.git
   ```

2. Navigate to the repository's directory:
   ```sh
   cd 0x01-Embedded_Linux_App_Dev/Task5(Implement a multi-function command)/fhCommand_dir
   ```

3. Run the following commands to build the project and tests:
   ```sh
   cmake -S . -B ./build -DCMAKE_INSTALL_PREFIX=./build/

   cmake --build build --target install
   ```
4. Run the tests to ensure the components' functionality:
   ```sh
   ./build/bin/FileHandlerTests

   ./build/bin/RequesterTests
   ```
4. Run the `RequesterApp` or `FileHandlerApp` to interact with the components:
   ```sh
   ./build/bin/RequesterApp

   ./build/bin/FileHandlerApp
   ```
5. Review the run_logs.txt file for a log of the project's execution.