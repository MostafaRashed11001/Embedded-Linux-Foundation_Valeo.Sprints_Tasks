#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include <string>

#define APP_NAME  "App_1"       // Define the application name.
#define Queue_Name "/my_queue"  // Define the queue name.
#define Manual_Path "../../Mathematical_Operation_App/MathAppManual.txt"

// Function to check if a string represents a number.
bool check_number(std::string str);

// Function to display the manual from a file.
void displayManual(void);

#endif // CALCULATOR_APP_H