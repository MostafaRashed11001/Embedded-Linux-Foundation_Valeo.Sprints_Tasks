# IPC Library

The IPC Library facilitates inter-process communication by managing message queues. It provides a straightforward and reliable method for different processes to exchange data. This documentation covers the key components and usage of the IPC Library.

# MessageQueueReceiver Class

## Constructor

MessageQueueReceiver(const std::string& queueName): Initializes the message queue receiver with the given `queueName`.

1. `Parameters`:
   - `queueName`(string): The name used to create or connect to the message queue.

2. `Throws`:
   - `IPCException`: if an error occurs during message queue creation or connection.

## Methods

1. `Ensures that the message queue exists before performing operations.`

2. `receiveSync()`:
   - Synchronously receives a message from the message queue.
   - `Returns`: A string containing the received message.

3. `receiveAsync()`:
   - Asynchronously receives a message from the message queue.
   - `Returns`: A string containing the received message, or "No message received asynchronously" if no message is available.

# MessageQueueSender Class

## Constructor

MessageQueueSender(const std::string& queueName): Initializes the message queue sender by connecting to an existing message queue with the given `queueName`.
    - `Parameters` :

1. `Parameters`: 
   - `queueName`(string): The name used to create or connect to the message queue.

2. `Throws`:
   - `IPCException`: if the message queue does not exist or if an error occurs during connection.

## Methods

1. `connectQueue()`:
   - Ensures that the message queue is connected before sending messages.
   - `IPCException` if the message queue is not connected.

2. `sendMessage(const std::string& message)`:
   - Sends a message to the connected message queue.
   - `message` (string): The message to be sent.

# Usage

1. `Include Header Files`: Include the necessary header file, `IPC_Library`.h, in your application to use the IPC Library.

2. `Initialize MessageQueueReceiver or MessageQueueSender`: Initialize an instance of `MessageQueueReceiver` or `MessageQueueSender` with the desired `queueName`.

3. `Perform Operations`: Use the provided methods to create/connect to a message queue, send messages, and receive messages synchronously or asynchronously.

4. `Error Handling`: Handle exceptions of type `IPCException` that may be thrown during message queue operations.

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)