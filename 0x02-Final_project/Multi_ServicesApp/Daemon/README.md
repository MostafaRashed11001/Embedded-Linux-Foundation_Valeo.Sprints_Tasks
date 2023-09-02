# Daemon Library 

The Daemon Logger Library offers functions to daemonize processes efficiently. This library helps create daemon processes, which are background processes that run independently of the terminal. Daemon processes are commonly used for tasks like logging, network services, and system monitoring. This documentation covers the key components and usage of the Daemon Logger Library.

# Daemon Function

## Functionality

`Daemon`(int flags): Daemonizes the current process by following a series of steps.

- `Parameters`:
   - `flags`(int): A set of flags that control the daemonization process.

## Flags

The `flags` parameter is a combination of the following flags:

1. `BD_NO_UMASK0`: Prevents resetting the file mode creation mask (umask) to zero.

2. `BD_NO_CHDIR`: Prevents changing the current working directory to the root directory.

3. `BD_NO_CLOSE_FILES`: Prevents closing all open file descriptors.

4. `BD_NO_REOPEN_STD_FDS`: Prevents reopening standard file descriptors to /`dev/null`.

## Steps

The `Daemon` function performs the following steps to daemonize the process:

1. `First Fork`: Creates a child process using the `fork` system call. The parent process exits.

2. `Session Leader`: Makes the child process the leader of a new session using `setsid`. This ensures that the process is not a session leader and can't reacquire a controlling terminal.

3. `Second Fork`: Forks again to create another child process. The parent process exits, leaving only the second child process.

4. `Reset Umask`: Resets the file mode creation mask (umask) to zero, unless the `BD_NO_UMASK0` flag is set.

5. `Change Working Directory`: Changes the current working directory to the root directory (`/`), unless the `BD_NO_CHDIR` flag is set.

6. `Close File Descriptors`: Closes all open file descriptors, unless the `BD_NO_CLOSE_FILES` flag is set.

7. `Reopen Standard File Descriptors`: Reopens standard file descriptors (stdin, stdout, stderr) to `/dev/null`, unless the `BD_NO_REOPEN_STD_FDS` flag is set.

## Return Value

- Returns `0` if the daemonization process is successful.
- Returns `-1` if an error occurs during the daemonization process.

# Usage

1. `Include Header Files`: Include the necessary header file, `daemon.h`, in your application to use the Daemon Logger Library.

2. `Call Daemon Function`: Call the `Daemon` function with the desired flags to daemonize your process.

3. `Error Handling`: Check the return value of the `Daemon` function to handle any errors that may occur during the daemonization process.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)