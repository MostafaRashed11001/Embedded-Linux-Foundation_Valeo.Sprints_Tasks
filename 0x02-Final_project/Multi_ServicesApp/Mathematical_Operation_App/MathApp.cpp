#include "MathApp.h"
#include "../IPC_LIBRARY/IPC_Library.h"
#include "../Utils/Utils.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

// Class representing the calculator application.
class CalculatorApp {
private:
    MessageQueueSender Sender; // MessageQueueSender instance for sending logs.
    
public:
    // Constructor to initialize the CalculatorApp with a MessageQueueSender.
    CalculatorApp(MessageQueueSender &CalcuSender) : Sender(CalcuSender) {}

    // Perform a mathematical operation and send the log message.
    void performOperation(double num1, double num2, char operation) {
        double result;
        std::string logMessage;
        
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    logMessage = std::string(MathApp) + "Error: Division by zero.\n";
                }
                break;
            default:
                logMessage = std::string(MathApp) + "Error: Invalid operation.\n";
        }
        
        if (logMessage.empty()) {
            logMessage = "Result of " + std::to_string(num1) + " " + operation + " " +
                         std::to_string(num2) + " = " + std::to_string(result) + "\n";
        }
        
        // Send log message to the logger
        Sender.sendMessage(logMessage);
        std::cout << logMessage << std::endl;
    }
};

int main(int argc, char *argv[]) {

    // Create a sender for the CalculatorApp to use
    MessageQueueSender AppSender(Queue_Name);
    AppSender.connectQueue();
    AppSender.sendMessage(APP_NAME);
    AppSender.sendMessage(Queue_Name);
    
    // Create the CalculatorApp instance
    CalculatorApp calculator(AppSender);
    
    // Check the command-line arguments and perform operations.
    if (argc == 4) {
        if (check_number(argv[2]) && check_number(argv[3])) {
            // Check for specific arguments related to list or read commands
            if (strcmp(argv[1], "Sum") == 0) {
                calculator.performOperation(std::stod(argv[2]), std::stod(argv[3]), '+');
            } else if  (strcmp(argv[1], "Sub") == 0) {
                calculator.performOperation(std::stod(argv[2]), std::stod(argv[3]), '-');
            } else if  (strcmp(argv[1], "Mul") == 0) {
                calculator.performOperation(std::stod(argv[2]), std::stod(argv[3]), '*');
            } else if  (strcmp(argv[1], "Div") == 0) {
                calculator.performOperation(std::stod(argv[2]), std::stod(argv[3]), '/');
            } else {
                displayManual();
                AppSender.sendMessage(std::string(MathApp) + "Invalid input: Operations should be {Sum, Sub, Mul, Div}.\n");
            }
        }
        else {
            displayManual();
            AppSender.sendMessage(std::string(MathApp) + "Invalid input: Arguments should be numbers.\n"); 
        }
    } else if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
        displayManual();
        AppSender.sendMessage(std::string(MathApp) + "User requested help using --help command.\n");
        }
    } else {
        displayManual();
        AppSender.sendMessage(std::string(MathApp) + "Invalid input: Incorrect number of arguments.\n");
    }

    return 0;
}

// Function to check if a string represents a number.
bool check_number(std::string str)
{
   for (int digit = 0; digit < str.length(); digit++) {

        if (isdigit(str[digit]) == false) {
            return false; // If any character is not a digit, return false.
        }
    }
    return true; // If all characters are digits, return true.
}

// Function to display the manual from a file.
void displayManual(void) {
    std::ifstream manualFile(Manual_Path);
    if (manualFile.is_open()) {
        std::string line;
        while (getline(manualFile, line)) {
            std::cout << line << std::endl; // Print each line of the manual file.
        }
        manualFile.close();                 // Close the file after reading.
    } else {
        ClinetLogger("Error opening manual file.\n", ERROR , Math);
    }
}
