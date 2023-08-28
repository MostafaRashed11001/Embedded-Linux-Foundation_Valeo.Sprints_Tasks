#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <semaphore.h>
#include <fstream>

using namespace std;

#define pathLength 512
#define memSize 512
#define AccessPermissions_shm 0666
#define AccessPermissions_sem 0644
static char *virtualMemoryAdd = NULL;
static sem_t *semptr;
static char *finalPath;

/**
 * Reports an error message and exits the program.
 *
 * This function prints the given error message followed by a description of the error,
 * using the perror function. It then terminates the program with a failure status.
 *
 * Input:  msg The error message to be reported.
 */
void report_and_exit(const char* msg);

/**
 * Lists the contents of a directory.
 *
 * This function takes a directory path as input and returns a string containing
 * the names of files and subdirectories within the specified directory.
 *
 * Input:  path The path of the directory to be listed.
 * return: A string containing the list of directory contents.
 */
string list_dir(const char *path);

/**
 * Reads the content of a file.
 *
 * This function takes a filename as input and returns a string containing
 * the content of the specified file.
 *
 * Input:  filename The name of the file to be read.
 * return: A string containing the content of the file.
 */
string read_file_content(const char *filename);

/**
 * Receives data from a named pipe.
 *
 * This function reads data from the named pipe and stores it in the provided file.
 *
 * Input:  file The path of the file to store the received data.
 * Input:  fileDescriptor A pointer to the file descriptor of the named pipe.
 * return: Returns the number of bytes read from the pipe.
 */
int Rec_Pipe(const char* file, int *fileDescriptor);

/**
 * Creates and maps shared memory.
 *
 * This function creates a shared memory segment and maps it to a virtual memory address.
 *
 * Input:  memoryName The name of the shared memory segment.
 * return: Returns true if shared memory creation and mapping are successful, false otherwise.
 */
bool creatShared(const char *memoryName);

/**
 * Creates or opens a semaphore.
 *
 * This function creates or opens a semaphore based on the given semaphore name.
 * It also takes a semaphore status to determine whether the semaphore should start locked or unlocked.
 *
 * Input:  semName The name of the semaphore.
 * Input:  semStatus The status of the semaphore ("lock" or "unlock").
 * return: Returns true if semaphore creation or opening is successful, false otherwise.
 */
bool CreateSemaphore(const char *semName, const char *semStatus);


#endif /* FILEHANDLER_H_ */