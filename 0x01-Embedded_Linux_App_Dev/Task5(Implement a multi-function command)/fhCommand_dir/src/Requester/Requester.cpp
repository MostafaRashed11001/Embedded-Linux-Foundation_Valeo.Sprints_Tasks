/**
 * file: Requester.cpp
 * brief: A Requester program that demonstrates file operations, shared memory, and semaphores.
 */
#include <iostream>
#include "Requester.h"
#include "gtest/gtest.h"
#include "../../logger/logger.h" // Include custom logger header
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <errno.h>
#include <semaphore.h>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    
    // Define constants and variables
    const char semaphoreName [10] = "Semaphore";       // Semaphore name
    char semaphoreState [10] = "lock";                 // Initial semaphore state
    const char* MemoryName = "/sharedMem";             // Shared memory name
    const char *pipeName = "../../Result/PipeChannel"; // Named pipe name
    char Default_File[] = "../../Result/DefaultFile";  // Default file path
    char Default_Dir[] = "../../Result/";              // Default directory path

    // Write in the named pipe
    if (!writePipe(pipeName, &fileDescriptorPipe)) {
        LOG_ERROR <<" [Reqester] Failed to write to the named pipe.";
    }

    // Handle command-line arguments
    if (argc == 3) {
        // Check for specific arguments related to list or read commands
        if (strcmp(argv[1], "fh") == 0 && strcmp(argv[2], "-l") == 0) {

            if (!listCommend (Default_Dir, fileDescriptorPipe)) {
                LOG_ERROR <<" [Reqester] Failed to execute listCommend.";
            }
            
        } else if (strcmp(argv[1], "fh") == 0 && strcmp(argv[2], "-r") == 0) {

            if (!readCommend (Default_File, fileDescriptorPipe)) {
                LOG_ERROR <<" [Reqester] Failed to execute readCommend.";
            }

        } else {
            LOG_ERROR <<" [Reqester] Incorrect args option...";
            report_and_exit("Incorrect args option...");
        }
    } else if (argc == 4) {
        if (strcmp(argv[1], "fh") == 0 && strcmp(argv[2], "-l") == 0) {

            if (!listCommend (argv[3], fileDescriptorPipe)) {
                LOG_ERROR <<" [Reqester] Failed to execute listCommend.";
            }

        } else if (strcmp(argv[1], "fh") == 0 && strcmp(argv[2], "-r") == 0) {

            if(!readCommend (argv[3], fileDescriptorPipe)) {
                LOG_ERROR <<" [Reqester] Failed to execute readCommend.";
            }

        } else {
            LOG_ERROR <<" [Reqester] Incorrect args option...";
            report_and_exit("Incorrect args option...");
        }
    } else {
        LOG_ERROR <<" [Reqester] Incorrect args Number...";
        report_and_exit("Incorrect args Number...");
    }

    if (sleep(1) != 0) {
       LOG_WARNING << "[Requester] Sleep interrupted ";
    }

    // Create shared memory
    if (!accessShared(MemoryName)) {
        LOG_ERROR <<" [Reqester] "<<"Failed to create shared memory.";
        report_and_exit("Failed to create shared memory...");
    }

    // Create semaphore
    if (!accessSemaphore(semaphoreName, semaphoreState, MemoryName)) {
        LOG_ERROR <<" [Reqester] "<< "Failed to create semaphore.";
        report_and_exit("Failed to create semaphore...");
    }

    // Unlink shared memory
    shm_unlink(virtualMemoryAdd);

    return 0;
}

// Function to execute the "list" command
bool listCommend (char *path, int fileDescriptorPipe){
    bool listStatus = true;

    // Construct the buffer for the named pipe
    char buffer[pathLength];

    // Format the buffer with the list command and provided path
    int check = snprintf(buffer, sizeof(buffer), "-l %s\n", path);
    if (check == 0) {
        LOG_WARNING <<" [listCommend] Failed to construct buffer for listCommend.";
    } else if (check < 0) {
         LOG_ERROR  <<" [listCommend] snprintf failed in listCommend: " << strerror(errno); 
    }
    
    // Write the buffer to the named pipe
    if (write(fileDescriptorPipe, buffer, strlen(buffer)) == -1) {
        LOG_ERROR << " [listCommend] Failed to write to the named pipe in listCommend: " << strerror(errno);
        listStatus = false;
        report_and_exit("Buffer was not declared");
    }
    return listStatus;
}

// Function to execute the "read" command
bool readCommend (char *path, int fileDescriptorPipe){
    bool readStatus = true;

    // Construct the buffer for the named pipe
    char buffer[pathLength];
    int check = snprintf(buffer, sizeof(buffer), "-r %s\n", path);
    
    if (check == 0) {
        LOG_WARNING << " [readCommend] Failed to construct buffer for readCommend.";
    } else if (check < 0) {
        LOG_ERROR << " [readCommend] snprintf failed in readCommend: " << strerror(errno);
    }
    
    // Write the buffer to the named pipe
    if (write(fileDescriptorPipe, buffer, strlen(buffer)) == -1) {
        LOG_ERROR << " [readCommend] Failed to write to the named pipe in readCommend: " << strerror(errno);
        report_and_exit("Buffer was not declared");
        readStatus = false;
    }
    return readStatus;
}

// Function to report an error and exit the program
void report_and_exit(const char* msg) {
    perror(msg); // Prints the error message followed by a description of the error
    exit(-1);    // Exits the program with the status code representing failure (EXIT_FAILURE)
}

// Function to open and write to a named pipe
bool writePipe(const char *pipeName, int *fileDescriptorPipe) {
    bool pipeStatus = true;

    // Open the named pipe for writing and create it if it doesn't exist
    *fileDescriptorPipe = open(pipeName,O_WRONLY | O_APPEND, S_IRWXG | S_IRWXO | S_IRWXU); 

    if (*fileDescriptorPipe == -1) {
        LOG_ERROR << "[writePipe] Can't get file descriptor for named pipe: " << strerror(errno);
        pipeStatus = false;
        report_and_exit("Can't get file descriptor.....");  // Report error and exit if opening the pipe fails
    }
    
    return pipeStatus;  // Return the status of named pipe creation and opening
}

// Function to access and map shared memory
bool accessShared(const char *memoryName) {
    bool sharedStatus = true;
    
    // Open the shared memory segment for reading and writing
    int fileDescriptorShared = shm_open(memoryName, O_RDONLY, AccessPermissions_shm);//O_RDWR
    
    if (fileDescriptorShared == -1) {
        LOG_ERROR << "[accessShared] Can't get file descriptor for shared memory: " << strerror(errno);
        sharedStatus = false;
        report_and_exit("Can't get file descriptor...");  // Report error and exit if opening the shared memory fails
    } else {
        // Map the shared memory segment to a virtual memory address
        virtualMemoryAdd = static_cast<char*>(mmap(NULL, memSize, PROT_READ, MAP_SHARED, fileDescriptorShared, 0));

        if (virtualMemoryAdd == MAP_FAILED) {
            LOG_ERROR << "[accessShared] Failed to map shared memory: " << strerror(errno);
            sharedStatus = false;
            report_and_exit("Failed to map shared memory...");  // Report error and exit if mapping the shared memory fails
        }
    }
	return sharedStatus;  // Return the status of shared memory creation and mapping
}

// Function to access and operate on a semaphore
bool accessSemaphore(const char *semName, const char *semStatus, const char *memoryName) {
    bool semaphoreStatus = true;
    int binarySemaphore = 0;  // Default binary semaphore value
    
    // Determine the binary semaphore value based on semStatus
    if (strcmp(semStatus, "lock") == 0) {
        binarySemaphore = 0;
    } else if (strcmp(semStatus, "unlock") == 0) {
        binarySemaphore = 1;
    } else {
        LOG_ERROR << "[accessSemaphore] Unavailable semaphore status: " << semStatus;
        semaphoreStatus = false;
        report_and_exit("Unavailable semaphore status...");  // Report error and exit for invalid semaphore status
    }
    
    // Create and open the semaphore
    semptr = sem_open(semName, AccessPermissions_sem, binarySemaphore);
    if (semptr == SEM_FAILED) {
        LOG_ERROR << "[accessSemaphore] Failed to create/open semaphore: " << strerror(errno);
        semaphoreStatus = false;
        report_and_exit("Failed to create/open semaphore");  // Report error and exit if creating/opening the semaphore fails
    }
    
    if (!sem_wait(semptr)) { /* wait until semaphore != 0 */
        LOG_TRACE << "[accessSemaphore] Semaphore wait successful";
        for (int i = 0; i < strlen(virtualMemoryAdd); i++) {
            if(write(STDOUT_FILENO, virtualMemoryAdd + i, 1) == -1) {
                LOG_ERROR << "[accessSemaphore] Error writing to STDOUT: " << strerror(errno);
            }
        }
        cout << "\n";
        // Release the semaphore
        if(sem_post(semptr) == -1) {
            LOG_ERROR << "[accessSemaphore] Failed to release semaphore: " << strerror(errno);
        }
    }

    shm_unlink(memoryName);
    sem_close(semptr);
    
    return semaphoreStatus;  // Return the status of semaphore creation, opening, and operations
}
