
#include <iostream>
#include <vector>
#include "FileHandler.h"
#include "gtest/gtest.h"
#include "../../logger/logger.h" // Include custom logger header
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <fstream>
#include <errno.h>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

using namespace std;

// Function to report an error and exit the program
void report_and_exit(const char* msg) {
    perror(msg); // Prints the error message followed by a description of the error
    exit(-1);    // Exits the program with the status code representing failure (EXIT_FAILURE)
}

// Function to list files in a directory
string list_dir(const char *path) {

    string File_list;            // To store the list of file names
    struct dirent *entry;        // To store information about each directory entry
    
    DIR *dir = opendir(path);    // Open the specified directory
    if (dir == NULL) {
        LOG_ERROR << "[list_dir] Error opening directory: " << strerror(errno);
        report_and_exit("Error opening directory");  // Report error and exit if opening the directory fails
    }

    // Loop through each directory entry
    while ((entry = readdir(dir)) != NULL) {  // Loop through each directory entry
        if (entry->d_type == DT_REG) {         // Check if it's a regular file
            File_list += entry->d_name;        // Append the file name to the list
            File_list += "\n";                 // Add a newline after each file name
        }
    }

   closedir(dir);  // Close the directory
    
    return File_list;  // Return the list of file names
}

// Function to read the content of a file
string read_file_content(const char *filename) {

    ifstream file(filename);  // Open the specified file for reading
    if (!file.is_open()) {
        LOG_ERROR << "[read_file_content] Error opening file: " << strerror(errno);
        report_and_exit("Error opening file");  // Report error and exit if opening the file fails
    }

    string content;                  // To store the file content
    string line;                     // To store each line read from the file
    while (getline(file, line)) {    // Read each line from the file
        content += line + "\n";      // Append the line to the content, along with a newline
    }

    file.close();  // Close the file
    
    return content;  // Return the accumulated content of the file
}

// Function to receive operation code and extracted file path from a named pipe.
int Rec_Pipe(const char* file, int *fileDescriptor) {
    int recOption = -1;

    *fileDescriptor = open(file,  O_CREAT | O_RDONLY | O_APPEND, S_IRWXG | S_IRWXO | S_IRWXU); // Open the named pipe for reading

    ifstream filename(file);  // Open the file for reading using ifstream
    if (*fileDescriptor == -1) {
        LOG_ERROR << "[Rec_Pipe] Can't get file descriptor: " << strerror(errno);
        report_and_exit("Can't get file descriptor...");  // Report error and exit if opening the pipe fails
    }

    string path, prvpath;
    // Read the last line from the named pipe file
    while (true){  // Read the last line from the named pipe file
        getline(filename, path);
        if (path == "")
        {
            path = prvpath;
            break;
        }
        prvpath = path;
        path = "";
    }
    ofstream outputFile(file, ios::trunc);
    // Find the position of the space after "-l"
    size_t spacePos = path.find(' ');

    // Extract the option portion
    string option;
    if (spacePos != string::npos && spacePos > 0) {
        // Set the recOption based on the extracted option
        if (path[spacePos-1] == 'l') {
            recOption = 1;
        } else if (path[spacePos-1] == 'r') {
            recOption = 0;
        }
    }
    // Allocate memory for finalPath and copy extracted path
    finalPath = new char[path.size() + 1];
    strcpy(finalPath, path.c_str());
    
    return recOption;  // Return the extracted option
}

// Function to create or open shared memory
bool creatShared(const char *memoryName) {

    bool sharedStatus = true;

    // Create or open shared memory
    int fileDescriptorShared = shm_open(memoryName, O_CREAT | O_RDWR, AccessPermissions_shm); // Create or open shared memory
    if (fileDescriptorShared == -1) {
        LOG_ERROR << "[creatShared] Failed to create shared memory: " << strerror(errno);
        sharedStatus = false;
        report_and_exit("Failed to create shared memory...");
    } else {
        // Set the size of shared memory
        int ftruncateResult = ftruncate(fileDescriptorShared, memSize); // Set the size of shared memory
        if (ftruncateResult == -1) {
            LOG_ERROR << "[creatShared] Failed to allocate memory size: " << strerror(errno);
            sharedStatus = false;
            report_and_exit("Failed to allocate memory size...");
        } else {
            // Map memory to address space
            virtualMemoryAdd = static_cast<char*>(mmap(NULL, memSize, PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptorShared, 0)); // Map memory to address space
            if (virtualMemoryAdd == MAP_FAILED) {
                LOG_ERROR << "[creatShared] Failed to map shared memory: " << strerror(errno);
                sharedStatus = false;
                report_and_exit("Failed to map shared memory...");
            }
        }
    }

    return sharedStatus;
}

// Function to create or open a semaphore
bool CreateSemaphore(const char *semName, const char *semStatus) {

    bool semaphoreStatus = true;
    int binarySemaphore = 0;

    // Determine binarySemaphore value based on semStatus
    if (strcmp(semStatus, "lock") == 0) {
        binarySemaphore = 0;
    } else if (strcmp(semStatus, "unlock") == 0) {
        binarySemaphore = 1;
    } else {
        LOG_ERROR << "[CreateSemaphore] Invalid semaphore status";
        semaphoreStatus = false;
        report_and_exit("Invalid semaphore status...");
    }

    // Create or open the semaphore with the specified name, initial status, and access permissions
    semptr = sem_open(semName, O_CREAT, AccessPermissions_sem, binarySemaphore);
    if (semptr == (void *)-1) {
        LOG_ERROR << "[CreateSemaphore] Failed to create semaphore: " << strerror(errno);
        semaphoreStatus = false;
        report_and_exit("Failed to create semaphore...");
    }
    
    return semaphoreStatus;
}