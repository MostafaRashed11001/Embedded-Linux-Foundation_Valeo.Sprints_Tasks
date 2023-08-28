#ifndef REQUESTER_H_
#define REQUESTER_H_

#include <semaphore.h>

using namespace std;

#define pathLength 2048
#define memSize 512
#define AccessPermissions_shm 0666
#define AccessPermissions_sem 0644
static char *virtualMemoryAdd = NULL;
static sem_t *semptr;
static int fileDescriptorPipe = -1;


/**
 * Reports an error message and exits the program.
 *
 * This function prints the given error message followed by a description of the error,
 * using the perror function. It then terminates the program with a failure status.
 *
 * Input: msg The error message to be reported.
 */
void report_and_exit(const char* msg);

/**
 * Writes data to a named pipe.
 *
 * This function opens a named pipe for writing and creates it if it doesn't exist.
 * It then writes data to the pipe using the provided file descriptor.
 *
 * Input:  pipeName The path to the named pipe.
 * Input:  fileDescriptorPipe A pointer to the file descriptor for the named pipe.
 * return: Returns true if the writing operation is successful, false otherwise.
 */
bool writePipe(const char *pipeName, int *fileDescriptorPipe);

/**
 * Accesses and maps a shared memory segment.
 *
 * This function opens a shared memory segment for reading and writing.
 * It then maps the shared memory to a virtual memory address.
 *
 * Input:  memoryName The name of the shared memory segment.
 * return: Returns true if accessing and mapping the shared memory is successful, false otherwise.
 */
bool accessShared(const char *memoryName);

/**
 * Accesses and operates on a semaphore.
 *
 * This function creates or opens a semaphore based on the given semaphore name.
 * It also takes a semaphore status to determine whether the semaphore should start locked or unlocked.
 * The function waits for the semaphore to be unlocked, performs operations on shared memory,
 * and then releases the semaphore.
 *
 * Input:  semName The name of the semaphore.
 * Input:  semStatus The status of the semaphore ("lock" or "unlock").
 * Input:  memoryName The name of the associated shared memory segment.
 * return: Returns true if semaphore operations are successful, false otherwise.
 */
bool accessSemaphore(const char *semName, const char *semStatus, const char *memoryName);

/**
 * Executes the "read" command.
 *
 * This function constructs a buffer containing the "read" command and the provided file path.
 * It then writes the buffer to the named pipe using the given file descriptor.
 *
 * Input:  path The path of the file to be read.
 * Input:  fileDescriptorPipe The file descriptor of the named pipe.
 * return: Returns true if writing to the named pipe is successful, false otherwise.
 */
bool readCommend(char *path, int fileDescriptorPipe);

/**
 * Executes the "list" command.
 *
 * This function constructs a buffer containing the "list" command and the provided directory path.
 * It then writes the buffer to the named pipe using the given file descriptor.
 *
 * Input:  path The path of the directory to be listed.
 * Input:  fileDescriptorPipe The file descriptor of the named pipe.
 * return: Returns true if writing to the named pipe is successful, false otherwise.
 */
bool listCommend(char *path, int fileDescriptorPipe);


#endif /* REQUESTER_H_ */