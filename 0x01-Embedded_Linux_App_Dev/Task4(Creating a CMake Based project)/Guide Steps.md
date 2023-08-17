## Guide Steps

1. Creating Parent directore and subdirectores with files to build a tree of the project (as Requirements):
   ```sh
   mkdir -p project_dir/include  project_dir/src project_dir/library
   
   touch project_dir/include/WriteInFile.h project_dir/include/Print.h project_dir/src/main.cpp project_dir/src/Print.cpp project_dir/library/WriteInFile.cpp project_dir/src/CMakeLists.txt project_dir/library/CMakeLists.txt project_dir/CMakeLists.txt
   ```

2. Navigate to the Parent's directory:
   ```sh
   cd project_dir
   ```
3. Project Components:
- `main.cpp`: This is the main application file.
- `print.cpp`: This source file is used in the main application to print 'Hello World' to the console.
- `WriteInFile.cpp`: This source file is compiled as a static library and is used to create a `helloWorld.txt` file, writing 'Hello World' into it.
- `print.h` and `WriteInFile.h`: These header files contain prototypes for my source files.
- `CMakeLists.txt`: This text file is provided to CMake to generate the build system based on it.

4. Generate MakeFile using CMake :
   ```sh
   cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./build/
   ```
5. Generate executable file using MakeEile with CMake :
   ```sh
   cmake --build build --target install
   ```
6. Testcasses to test my executable environment:
   ```sh
   ./build/bin/FinalTarget -f ->  will create file named helloWorld.txt and write "helloWorld" to it.
   ./build/bin/FinalTarget -c ->  will print "helloWorld" to the console.
   ./build/bin/FinalTarget -"any arg" -> Usage: ./FinalTarget -f or -c
   ```