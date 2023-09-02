#ifndef IPC_LIBRARY_H
#define IPC_LIBRARY_H

#include <string>
#include <stdexcept>

// Class for receiving messages from an IPC message queue.
class MessageQueueReceiver {
public:
    // Constructor to initialize the message queue receiver.
    MessageQueueReceiver(const std::string& queueName);

    // Method to check and ensure the message queue exists before operations.
    void createQueue();

    // Method to synchronously receive a message from the message queue.
    std::string receiveSync();

    // Method to asynchronously receive a message from the message queue.
    std::string receiveAsync();

private:
    int msgId;          // Identifier for the message queue.
    bool queueExists;   // Flag indicating if the message queue exists.
};

// Class for sending messages to an IPC message queue.
class MessageQueueSender {
public:
    // Constructor to initialize the message queue sender.
    MessageQueueSender(const std::string& queueName);

    // Method to check and ensure the message queue is connected before sending messages.
    void connectQueue();

    // Method to send a message to the message queue.
    void sendMessage(const std::string& message);

private:
    int msgId;             // Identifier for the message queue.
    bool queueConnected;   // Flag indicating if the message queue is connected.
};

// Custom exception class for IPC-related errors.
class IPCException : public std::runtime_error {
public:
    // Constructor to initialize the IPCException with an error message.
    IPCException(const std::string& message) : std::runtime_error(message) {}
};

#endif
