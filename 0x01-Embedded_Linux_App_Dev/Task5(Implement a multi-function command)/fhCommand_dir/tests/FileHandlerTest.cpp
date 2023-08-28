#include "gtest/gtest.h"
#include "../src/fh/FileHandler.h" // Include the header file of the component you are testing

// Define a test suite named "FileHandlerTest"
TEST(FileHandlerTest, ListDirectory) {
    // Test the list_dir function
    
    const char* path = "../../Result/GTest_Dir_Run/";

    // Call the function
    string result = list_dir(path);
    
    // Assert the result and other expectations
    ASSERT_EQ(result, "File1\nREAD_FILE\nFile_2\n"); // Replace with actual assertion
}

TEST(FileHandlerTest, ReadFileContent) {
    // Test the read_file_content function
    
    const char* filename = "../../Result/GTest_Dir_Run/READ_FILE";

    // Call the function
    string result = read_file_content(filename);
    
    // Assert the result and other expectations
    ASSERT_EQ(result, "GTEST_RUN_\"-r\"->COMMEND_SUCCESSFULLY\n"); // Replace with actual assertion
}

// The main function for running the tests
int main(int argc, char **argv)
{
     // Initialize Google Test framework with command line arguments
    ::testing::InitGoogleTest(&argc, argv);

    // Run all the defined tests and return the results
    return RUN_ALL_TESTS();
}
