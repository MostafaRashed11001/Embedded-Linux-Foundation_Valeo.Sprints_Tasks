# Requester

The `Requester` program demonstrates file operations, shared memory, and semaphore usage. It interacts with a named pipe to send commands for listing directories and reading files. It also creates and accesses shared memory segments and operates on semaphores to synchronize processes.

## Project Structure

1. `Requester.cpp`:
   - `Main Function`: This is the entry point of the program. It reads command-line arguments, performs file operations, interacts with named pipes, creates shared memory, and operates on semaphores.
   - `Command-line Arguments`: The program takes command-line arguments to determine the type of action to be performed and the path or file to be operated on.
   - `Write to Named Pipe`:  The program uses the writePipe function to write data to a named pipe.
   - `List and Read Commands`:  The listCommend and readCommend functions are used to construct commands for listing directories and reading files, respectively. These commands are then written to the named pipe.
   - `Shared Memory and Semaphore`: The program accesses shared memory using the accessShared function and operates on a semaphore using the accessSemaphore function.

2. `Requester.h`: Contains function prototypes, constants, and global variables used in the Requester.cpp file.

3. `SrcRequester.cpp`: This file contains the implementations of the functions declared in Requester.h, including `listCommend`, `readCommend`, `writePipe`, `accessShared`, and `accessSemaphore`.

4. `CMakeLists.txt`: It creates an executable target named `RequesterApp` using Requester.cpp and links it to the Logger library.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)
- After successful compilation, you will have an executable named RequesterApp.

## Usage

Run the `RequesterApp` executable with appropriate command-line.

1. `./RequesterApp [command] [option] [path]`:
   - `[command]`: Specify the command to execute (fh for file handling).
   - `[option]` : Use -l to list files/directories or -r to read a file.
   - `[path]` : Provide the path to the file or directory for the command.
2. `Examples`:
   - `./RequesterApp fh -l`: To list files in the default path.
   - `./RequesterApp fh -r`: To read a file in the default path.
   - `./RequesterApp fh -l /path/to/directory`: To list files/directories in a specific path.
   - `./RequesterApp fh -r /path/to/file`: To read a file in a specific path.