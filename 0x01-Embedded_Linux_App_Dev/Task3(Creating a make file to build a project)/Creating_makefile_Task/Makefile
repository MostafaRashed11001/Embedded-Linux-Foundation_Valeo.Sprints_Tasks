# Makefile for finalTarget C++ program

# Compiler and compiler flags
CXX=g++
CXXFLAGS=-c -w -o2 -std=c++11

# Paths
ProjectDir=/home/mostafa_rashed/Creating_makefile_Task/
INSTALL_PATH=$(ProjectDir)/build/usr/bin/

# Default target: Build the finalTarget executable
all:finalTarget
	

# Rule to build the finalTarget executable
finalTarget:main.o
	$(CXX) main.o -o finalTarget

# Rule to compile main.cpp into main.o object file
main.o:main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.o

# Clean target: Remove generated files
clean:
	@echo "Cleaning..."
	rm -f $(ProjectDir)finalTarget $(ProjectDir)*.o $(INSTALL_PATH)finalTarget

# Install target: Install finalTarget to INSTALL_PATH
install:finalTarget
	@echo "Installong..."
	mkdir -p $(INSTALL_PATH)
	cp $(ProjectDir)finalTarget $(INSTALL_PATH)
	chmod +x $(INSTALL_PATH)finalTarget
