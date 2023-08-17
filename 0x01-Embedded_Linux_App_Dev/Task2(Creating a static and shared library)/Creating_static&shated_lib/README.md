# Static library :

    The command used to build the static library :
        ar rcs libMath.a math_lib.o
```
This command is used to create a static library named libMath.a by archiving the object file math_lib.o.The ar command is used to manage and create archives (libraries) in Unix-like systems. The rcs flags are used with ar to create a new archive or update an existing one. The resulting library will contain the compiled code from the math_lib.o object file, which can be linked with other programs to use the functions and symbols defined in the math_lib.o file.
```

    The command to be used to link the static library to the test app :
        cc -o main_s.exe main.cpp -L. libMath.a -lstdc++
```		
    1- Compile and link the program 'main.cpp' with the static library 'libMath.a'
    2- The resulting executable will be named 'main_s.exe'
    3- The '-L.' flag specifies to search for libraries in the current directory
    4- The '-lstdc++' flag links the C++ standard library
```
## Tast Static library :
    
    Test generated executable file after linking my appliction with static library (libMath.a):
        ./Static_lib/main_s.exe



# Shared library :

    The command used to build the shared library :
        g++ -c -Wall -Werror -fpic math_lib.cpp -o libmath_h.o
```
    Compile the source file 'math_lib.cpp' with the following options:
	1- -c: Compile only, do not link
	2- -Wall: Enable all warning messages
        3- -Werror: Treat warnings as errors
        4- -fpic: Generate position-independent code (PIC) for shared libraries
        5- The output object file will be named 'libmath_h.o'
```
        g++ -shared -o libMath_h.so libmath_h.o		
```
	1- Compile the object file 'libmath_h.o' into a shared library named 'libMath_h.so'
        2- -shared: Create a shared library
        3- -o: Specify the output file name
        4- The resulting shared library will be named 'libMath_h.so'
```		

    The command used to link the shared library to the test app :
        gcc -Wall -o main_h.exe main.cpp -lstdc++ -Wl,-rpath=. libMath_h.so
```
    1- Compile the source file 'main.cpp' into an executable named 'main_h.exe'
    2- -Wall: Enable all compiler warnings
    3- -o: Specify the output file name
    4- -lstdc++: Link against the C++ standard library
    5- -Wl,-rpath=. : Set the runtime search path for libraries to the current directory
    6- libMath_h.so : Link against the shared library 'libMath_h.so'
```
## Tast Shared library :
    
    Test generated executable file after linking my appliction with Shared library (libMath_h.so):
        ./Shared_lib/main_h.exe