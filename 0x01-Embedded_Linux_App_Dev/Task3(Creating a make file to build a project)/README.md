# Creating a make file to build a project

This repository contains a simple C++ program along with a Makefile that can be used to compile and build the program. The program demonstrates the use of a Makefile for managing the build process and compiling the C++ source code.

## Contents

1. Introduction
2. Requirements
3. Usage
4. Makefile Explanation

## Introduction

The `main.cpp` file in this repository contains a basic C++ program that prints a success message to the console. The `Makefile` provides the necessary instructions to compile and build the program.

## Requirements

To compile and run the C++ program in this repository, you need to have the following installed:

- C++ Compiler (e.g., g++)
- Make Utility

## Usage

1. Clone the repository to your local machine using the following command:
   ```
   git clone https://github.com/your-username/your-repository.git
   ```

2. Navigate to the repository's directory:
   ```
   cd your-repository
   ```

3. Compile and build the program using the Makefile by running the following command:
   ```
   make all
   ```

4. Run the compiled program:
   ```
   ./finalTarget
   ```

5. To clean the generated files, use the following command:
   ```
   make clean
   ```

6. To install the compiled program, use the following command:
   ```
   make install
   ```

## Makefile Explanation

The `Makefile` provided in this repository includes the following targets and rules:

- `all`: The default target that builds the `finalTarget` executable.
- `finalTarget`: The rule to build the `finalTarget` executable by linking the `main.o` object file.
- `main.o`: The rule to compile `main.cpp` into the `main.o` object file.
- `clean`: The target to remove generated files, including the `finalTarget` executable and object files.
- `install`: The target to install the `finalTarget` executable to the specified installation path.

---