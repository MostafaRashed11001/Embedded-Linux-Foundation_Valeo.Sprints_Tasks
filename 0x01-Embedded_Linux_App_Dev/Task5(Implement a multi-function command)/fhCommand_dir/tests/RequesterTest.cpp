#include "gtest/gtest.h"
#include "../src/Requester/Requester.h" // Include the header file of the component you are testing

// Define a test suite named "RequesterTest"
TEST(RequesterTest, ListCommand) {
    // Test the listCommend function

    bool testWrite = writePipe("../../Result/PipeChannel", &fileDescriptorPipe);
    
    // Assert the result and other expectations
    ASSERT_TRUE(testWrite); // Replace with actual assertion

    // Set up necessary variables for testing
    char path[] = "../Result/GTest_Dir_Run/";
    const char* expectedBuffer = "-l ../Result/GTest_Dir_Run/\n";
    
    // Call the function
    bool result = listCommend(path, fileDescriptorPipe);
    
    // Assert the result and other expectations
    ASSERT_TRUE(result); // Replace with actual assertion
}

TEST(RequesterTest, ReadCommand) {
    // Test the readCommend function

    bool testWrite = writePipe("../../Result/PipeChannel", &fileDescriptorPipe);
    
    // Assert the result and other expectations
    ASSERT_TRUE(testWrite); // Replace with actual assertion
    
    // Set up necessary variables for testing
    char path[] = "../Result/GTest_Dir_Run/READ_FILE";
    const char* expectedBuffer = "-r ../Result/GTest_Dir_Run/READ_FILE\n";
    
    // Call the function
    bool result = readCommend(path, fileDescriptorPipe);
    
    // Assert the result and other expectations
    ASSERT_TRUE(result); // Replace with actual assertion
    
}

// The main function for running the tests
int main(int argc, char **argv) 
{
    // Initialize Google Test framework with command line arguments
    ::testing::InitGoogleTest(&argc, argv);

    // Run all the defined tests and return the results
    return RUN_ALL_TESTS();
}
