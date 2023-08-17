#include <iostream>
#include "math_lib.hpp" // Include the custom math library header

int main ()
{
    // Call functions from the math library and print the results
    std::cout << add(20,10)<<"\n";
    std::cout << sub(20,10)<<"\n";
    std::cout << mul(10,20)<<"\n";
    std::cout << sqrt(0)<<"\n";
    std::cout << sqrt(11)<<"\n";
    return 0; // Indicate successful program execution
}