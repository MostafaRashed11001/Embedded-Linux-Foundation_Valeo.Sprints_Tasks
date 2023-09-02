#include <sys/stat.h>
#include <fcntl.h>
#include "daemon.h"
#include "../Utils/Utils.h" // Include necessary header for utility functions.
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h> 
#include <string.h>
#include <iostream>
// Function to daemonize the process with specified flags.
int Daemon(int flags)
{
    int maxfd;
    int fd;

    // Fork the process to create a child process.
    switch (fork()) 
    { 
        case -1: 
            return -1;
        case 0: 
            break; // Child process continues.
        default: 
            _exit(EXIT_SUCCESS); // Parent process exits.
    }

    // Make the child process the leader of a new session.
    if (setsid() == -1)
    {
        ClinetLogger("Error becoming session leader.\n", ERROR, LogDaemon);
        return -1;
    }

    // Fork again to ensure the process is not a session leader and can't reacquire a controlling terminal.
    switch (fork()) 
    { 
        case -1: 
            return -1;
        case 0: 
            break; // Child process continues.
        default: 
            _exit(EXIT_SUCCESS); // Parent process exits.
    }

    // Reset the file mode creation mask.
    if (!(flags & BD_NO_UMASK0))
        umask(0);
    
    // Change the current working directory to the root directory.
    if (!(flags & BD_NO_CHDIR))
        chdir("/");
    
    // Close all open file descriptors.
    if (!(flags & BD_NO_CLOSE_FILES)) 
    { 
        maxfd = sysconf(_SC_OPEN_MAX);
    
        if (maxfd == -1) 
            maxfd = BD_MAX_CLOSE;
        
        for (fd = 0; fd < maxfd; fd++)
            close(fd);
    }

    // Reopen standard file descriptors to /dev/null.
    if (!(flags & BD_NO_REOPEN_STD_FDS)) 
    {
        close(STDIN_FILENO);
        
        fd = open("/dev/null", O_RDWR);
        
        if (fd != STDIN_FILENO) {
            ClinetLogger("Error reopening stdin.\n", ERROR, LogDaemon);
            return -1;
        }
            
        if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO) {
            ClinetLogger("Error reopening stdout.\n", ERROR, LogDaemon);
            return -1;
        }
        
        if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO) {
            ClinetLogger("Error reopening stderr.\n", ERROR, LogDaemon);
            return -1;
        }
    }
 return 0;
}
