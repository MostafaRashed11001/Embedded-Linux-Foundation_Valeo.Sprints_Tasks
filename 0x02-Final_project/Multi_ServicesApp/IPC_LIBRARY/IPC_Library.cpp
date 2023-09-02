#include "IPC_Library.h"          // Include the corresponding header file.
#include "../Utils/Utils.h"       // Include necessary header for utility functions.
#include <iostream>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

// Constructor for MessageQueueReceiver, initializes the message queue.
MessageQueueReceiver::MessageQueueReceiver(const std::string& queueName) : queueExists(false) {
    // Generate a unique key for the message queue.
    key_t myKey = ftok(queueName.c_str(), 65);

    // Create or get the message queue identifier.
    msgId = msgget(myKey, 0666 | IPC_CREAT);

    // Check if message queue creation/getting was successful.
    if (msgId == -1) {
        ClinetLogger("Error creating message queue" + std::string(strerror(errno)), ERROR , IPC);
        throw IPCException("Error creating message queue");
    }
    queueExists = true;
}

// Method to ensure the message queue exists before performing operations.
void MessageQueueReceiver::createQueue() {
    if (!queueExists) {
        ClinetLogger("Message queue does not exist", ERROR , IPC);
        throw IPCException("Message queue does not exist");
    }
}

// Method to receive a message synchronously from the message queue.
std::string MessageQueueReceiver::receiveSync() {
    struct msg_buffer {
        long msg_type;
        char msg[1000];
    } receivedMessage;

    // Receive the message from the message queue.
    msgrcv(msgId, &receivedMessage, sizeof(receivedMessage), 1, !IPC_NOWAIT);

    return std::string(receivedMessage.msg);
}

// Method to receive a message asynchronously from the message queue.
std::string MessageQueueReceiver::receiveAsync() {
    struct msg_buffer {
        long msg_type;
        char msg[1000];
    } receivedMessage;

    // Use IPC_NOWAIT flag for non-blocking receive.
    if (msgrcv(msgId, &receivedMessage, sizeof(receivedMessage), 1, IPC_NOWAIT) != -1) {
        return std::string(receivedMessage.msg);
    } else {
        return "No message received asynchronously.";
    }
}

// Constructor for MessageQueueSender, connects to an existing message queue.
MessageQueueSender::MessageQueueSender(const std::string& queueName) : queueConnected(false) {
    // Generate a unique key for the message queue.
    key_t myKey = ftok(queueName.c_str(), 65);

    // Get the message queue identifier.
    msgId = msgget(myKey, 0666);

    // Check if getting the message queue identifier was successful.
    if (msgId == -1) {
        ClinetLogger("Message queue does not exist" + std::string(strerror(errno)), ERROR , IPC);
        throw IPCException("Message queue does not exist");
    }
    queueConnected = true;
}

// Method to ensure the message queue is connected before sending messages.
void MessageQueueSender::connectQueue() {
    if (!queueConnected) {
        ClinetLogger("Message queue not connected", ERROR , IPC);
        throw IPCException("Message queue not connected");
    }
}

// Method to send a message to the message queue.
void MessageQueueSender::sendMessage(const std::string& message) {
    struct msg_buffer {
        long msg_type;
        char msg[1000];
    } messageToSend;

    // Prepare the message buffer.
    messageToSend.msg_type = 1;
    snprintf(messageToSend.msg, sizeof(messageToSend.msg), "%s", message.c_str());

    // Send the message to the message queue.
    if (msgsnd(msgId, &messageToSend, sizeof(messageToSend), 0) == -1) {
        ClinetLogger("Error sending message" + std::string(strerror(errno)), ERROR , IPC);
        throw IPCException("Error sending message");
    }
    ClinetLogger("Sent message: " + std::string(messageToSend.msg), INFO , IPC);
}
