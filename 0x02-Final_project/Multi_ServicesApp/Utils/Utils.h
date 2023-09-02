#ifndef UTILS_H
#define UTILS_H

#include <string>

// Log levels
#define TRACE   0
#define DEBUG   1
#define INFO    2
#define WARNING 3
#define ERROR   4
#define FATAL   5

// Log prefixes
#define MathApp      "  [MathApp]       "
#define LoggerDaemon "  [LoggerDaemon]  "
#define IPC_LIB      "  [IPC_LIB]       "
#define SocketServer "  [SocketServer]  "

// Component types
#define Math      0
#define LogDaemon 1
#define IPC       2
#define Socket    3

// Function to log messages with specific log level and component type
void ClinetLogger(std::string log, int TypeLog, int TypeFile);


#endif /* UTILS_H */