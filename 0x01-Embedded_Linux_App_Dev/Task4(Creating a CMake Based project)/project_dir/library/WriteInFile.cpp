#include <iostream>
#include <fstream> // Include the fstream header for file handling

using namespace std;

// Function to write "helloWorld" to a file named helloWorld.txt
void writeHelloWorldToFile(void)
{
    // Create an ofstream object named 'file' to handle file operations
    ofstream file("helloWorld.txt");

    // Check if the file is successfully opened
    if (file.is_open())
    {
        // Write "helloWorld" to the file and add a newline
        file << "helloWorld" << endl;

        // Close the file after writing
        file.close();

        // Display a success message
        cout << "File 'helloWorld.txt' created and written to." << endl;
    } 
    else 
    {
        // Display an error message if the file couldn't be opened
        cerr << "Failed to create/write to file." << endl;
    }
}