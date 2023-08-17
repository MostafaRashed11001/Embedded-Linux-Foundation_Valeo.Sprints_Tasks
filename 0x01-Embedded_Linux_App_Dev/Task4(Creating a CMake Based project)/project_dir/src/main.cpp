#include <iostream>
#include <string.h> // Include the cstring header for string manipulation
#include "Print.h" // Include your custom Print header
#include "WriteInFile.h" // Include your custom WriteInFile header

using namespace std;

int main(int argc, char *argv[])
{
    // Check if the program is executed with the correct number of arguments
    if (argc == 2 && strcmp(argv[1], "-f") == 0) 
    {
       writeHelloWorldToFile(); // Call the function to write in a file
    } 
    // Check if the program is executed with the correct command line argument
    else if (argc == 2 && strcmp(argv[1], "-c") == 0)
    {
        printHelloWorld(); // Call the function to print to the console
    }
    else 
    {
        // Display an error message for incorrect command line arguments
        cerr << "Usage: " << argv[0] << " -f or -c" << endl;
    }
    return 0; // Return 0 to indicate successful program execution
}