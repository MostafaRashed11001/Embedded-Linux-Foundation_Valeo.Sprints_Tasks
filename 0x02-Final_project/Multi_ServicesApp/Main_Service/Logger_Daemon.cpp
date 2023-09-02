#include "../IPC_LIBRARY/IPC_Library.h" // Include the IPC library header.
#include "../Daemon/daemon.h"           // Include the daemon library header.
#include "../Socket/Socket_Server.h"    // Include the socket server library header.
#include "../Utils/Utils.h"             // Include the utility functions header.
#include <iostream>
#include <fstream>
#include <string.h>
#include <nlohmann/json.hpp>            // Include the JSON library.
#include <string>
#include <errno.h>

using json = nlohmann::json;            // Define an alias for nlohmann::json.
json config;                            // JSON object to store configuration.

int main(void)
{
    std::string receivedApp_Name;
    std::string receivedQueueName;
    std::string receivedLog;

    // Read configuration from JSON file  "/etc/systemd/Logger_config.json"
    //std::ifstream configFile("../JSON/Logger_config.json");
    std::ifstream configFile("/etc/systemd/Logger_config.json");
    
    if (!configFile.is_open()) 
    {
        ClinetLogger("Error opening config file\n", ERROR, LogDaemon);
        return -1;
    }

    ClinetLogger("Config file opened successfully\n", INFO, LogDaemon);
    
    // Copy JSON info into the 'config' object.
    configFile >> config;
    configFile.close();

    // Create a message queue receiver
    MessageQueueReceiver receiver("/my_queue");

    // Demonstrate message queue creation and receiving
    receiver.createQueue();

    // Create Socket
    if (CreateSocket () == false) {
        ClinetLogger("Error creating socket\n", ERROR, LogDaemon);
    }

    // connect Socket
    if(ConnectSocket () == false) {
        ClinetLogger("Error connecting socket\n", ERROR, LogDaemon);
    }

    ClinetLogger("Socket created and connected\n", INFO, LogDaemon);

#if SysD
    // Initialize daemon process.
    if (Daemon(BD_NO_CHDIR | BD_NO_CLOSE_FILES | BD_NO_REOPEN_STD_FDS | BD_NO_UMASK0) == -1) {
        ClinetLogger("Error becoming daemon\n", ERROR, LogDaemon);
        return -1;
    }
  
    ClinetLogger("Daemon process initialized\n", INFO, LogDaemon);
#endif

    while (true) {
        // Receive application name through IPC Library (replace with actual IPC code).
        receivedApp_Name = receiver.receiveSync();

        // Check if the received application name is configured.
        if(config[receivedApp_Name] != nullptr)
        {
            ClinetLogger("Received app name: " + receivedApp_Name + "\n", INFO, LogDaemon);

            // Receive queue name associated with the application.
            receivedQueueName = receiver.receiveSync();

            // Check if the received queue name matches the configured queue name.
            if (config[receivedApp_Name]["Name_Q"] == receivedQueueName)  // For mory secuirty
            {
                ClinetLogger("Received queue name: " + receivedQueueName + "\n", INFO, LogDaemon);

                // Receive the log message.
                receivedLog = receiver.receiveSync();
                ClinetLogger("Received log: " + receivedLog + "\n", INFO, LogDaemon);
            }
            else 
            {
                // Log a warning if the received queue name doesn't match the configuration.
                ClinetLogger("App Queue: " + receivedQueueName + " not in config for App Name: " + receivedApp_Name + "\n", WARNING, LogDaemon);
            }
        }
        else
        {
            // Log a warning if the received application name is not in the configuration.
            ClinetLogger("App Name: " + receivedApp_Name + " not in config\n", WARNING, LogDaemon);
        }

    }

    return 0;
}

