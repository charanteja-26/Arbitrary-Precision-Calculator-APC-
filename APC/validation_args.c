#include "apc.h"

// Function to check if a string contains only digits
int isstringdigit(char *str)
{
    // Traverse each character of the string
    while(*str)
    {
        // If the character is not a digit, return 0 (false)
        if(!isdigit(*str))
            return 0;
        // Move to the next character
        str++;
    }
    // If all characters are digits, return 1 (true)
    return 1;
}

// Function to validate command-line arguments
int validation_args(int argc, char *argv[])
{
    // Check if the number of arguments is not equal to 4 
    // or if the first and third arguments are not strings of digits
    if(argc != 4 || !isstringdigit(argv[1]) || !isstringdigit(argv[3]))
    {
        // Return FAILURE if validation fails
        return FAILURE;
    }
    // Return SUCCESS if validation passes
    return SUCCESS;
}


