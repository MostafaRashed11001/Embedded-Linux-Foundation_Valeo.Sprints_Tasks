#include "STD_TYPES.hpp"
// Function to add two integers
sint64 add(sint32 input_one, sint32 input_two)
{
    return (input_one+input_two);
}
// Function to subtract two integers
sint32 sub(sint32 input_one, sint32 input_two)
{
    return (input_one-input_two);
}
// Function to multiply two integers
sint64 mul(sint32 input_one, sint32 input_two)
{
    return (input_one*input_two);
}
// Function to calculate square root of an unsigned 64-bit integer
uint32 sqrt(uint64 input)
{
    // Handle special case for input being 0
    if(input == 0)
    {
        return 0;
    }

    uint64 result = input; 
    // Iteratively calculate square root using the Babylonian method
    while (result > (input / result) )
    {
        result = (result + (input / result)) / 2;
    }
    // Convert result to 32-bit unsigned integer before returning
    return (static_cast <uint32>(result));
}