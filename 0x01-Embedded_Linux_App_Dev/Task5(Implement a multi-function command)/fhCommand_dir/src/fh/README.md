# FileHandler

The "FileHandler" component of your project. It's a program that demonstrates file operations, shared memory, and semaphores.

## FileHandler Structure

1. `FileHandler.cpp`: It performs various tasks related to file handling, shared memory, and semaphores based on the received operation code. The main loop continuously reads from a named pipe, processes the received data, and performs the necessary operations.
   - `list_dir(const char *path)`: This function takes a directory path (path) as input and returns a string containing the names of the regular files within the specified directory.
   - `read_file_content(const char *filename)`: This function takes a filename (filename) as input and returns a string containing the content of the file.
   - `Rec_Pipe(const char* file, int *fileDescriptor)`: This function receives data from a named pipe, extracts the operation code, and stores the extracted file path.It takes the path to the named pipe and a pointer to a file descriptor (fileDescriptor) as inputs.
   - `creatShared(const char *memoryName)`: This function creates or opens shared memory and maps it to a virtual memory address.
   - `CreateSemaphore(const char *semName, const char *semStatus)`: This function creates or opens a semaphore with a specified name and status.

2. `FileHandler.h`: This header file declares the prototypes functions and global variables used in FileHandler.cpp.

3. `SrcFileHandler.cpp`: This source file declares the functions used in FileHandler.cpp.

4. `CMakeLists.txt`: This CMake configuration file sets up the project build. It specifies the Boost libraries required, includes necessary directories, links libraries, and creates targets for building your project.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)
- After successful compilation, you will have an executable named FileHandlerApp

