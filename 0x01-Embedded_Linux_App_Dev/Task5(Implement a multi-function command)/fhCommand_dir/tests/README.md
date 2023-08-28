# FileHandler and Requester Test Suite

The `FileHandler` and `Requester` test suite demonstrates unit tests for the corresponding components of your project. These tests use the Google Test framework to validate the functionality of the components.

## Project Structure

1. `FileHandlerTest.cpp`: The file contains test cases to validate the functionality of the FileHandler component's functions.
   - `list_dir`: This function is tested to ensure correct listing of files in a directory. `ASSERT_EQ`
   - `read_file_content`: This function is tested to ensure proper reading of file contents. `ASSERT_EQ`

2. `RequesterTest.cpp`: The file contains test cases for the Requester component's functions.
   - `listCommend`:
      - A simulated write operation is performed on a pipe channel. `ASSERT_EQ`
   - `readCommend`:
      - A simulated write operation is performed on a pipe channel. `ASSERT_EQ`

## Requirements

To build and run the project, you need the following installed:

- CMake (version 3.1...3.27)
- C++ Compiler (e.g., g++)
- Google Test Framework.

## Usage

Run the `RequesterTests` or `FileHandlerTests` executable with appropriate command-line.

1. `FileHandler Tests` : Run the tests for the `FileHandler` component. `./FileHandlerTests`
2. `Requester Tests`: Run the tests for the `Requester` component. `./RequesterTests`