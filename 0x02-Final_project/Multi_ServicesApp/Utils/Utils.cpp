#include "Utils.h"
#include "../Socket/Socket_Server.h"
#include "../Boost_Logger/Logger.h"
#include <string>
#include <iostream>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

// Custom logger function to log messages using Boost.Log and send them through sockets
void ClinetLogger(std::string log, int TypeLog, int TypeFile) {

    // Determine the specific log file name based on TypeFile
    std::string fileName;
    bool SocketSendStatus = true;
    switch (TypeFile)
    {
    case Math:
        fileName = MathApp;
        break;
    case LogDaemon:
        fileName = LoggerDaemon;
        break;
    case IPC:
        fileName = IPC_LIB;
        break;
    case Socket:
        fileName = SocketServer;
        break;
    default:
        break;
    }

    // Log the message based on the severity level using Boost.Log macros
    switch (TypeLog)
    {
    case TRACE: 
        LOG_TRACE << fileName <<log;
        SocketSendStatus = SendSocketMassage (fileName + log + "\n"); 
        break;
    case DEBUG:
        LOG_DEBUG << fileName << log;
        SocketSendStatus = SendSocketMassage (fileName + log + "\n"); 
        break;
    case INFO:
        LOG_INFO << fileName << log;
        SocketSendStatus = SendSocketMassage ( fileName + log + "\n"); 
        break;
    case WARNING: 
        LOG_WARNING << fileName << log;
        SocketSendStatus = SendSocketMassage (fileName + log + "\n"); 
        break;
    case ERROR:
        LOG_ERROR << fileName << log;
        SocketSendStatus = SendSocketMassage (fileName + log + "\n"); 
        break;
    case FATAL:
        LOG_FATAL << fileName << log;
        SocketSendStatus = SendSocketMassage (fileName + log + "\n"); 
        break;
    default:
        break;
    }

    if (SocketSendStatus == false) {
        LOG_ERROR << SocketServer << "Error in SendSocketMassage\n";
    }
}