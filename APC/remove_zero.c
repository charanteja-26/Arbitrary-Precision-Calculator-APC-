#include "apc.h"

void remove_leading_zeros(char *str) 
{
    int i = 0, j = 0;

    // Find the first non-zero character
    while (str[i] == '0') 
    {
        i++;
    }
    
    // Shift all characters to the left
    while (str[i] != '\0')
    {
        str[j++] = str[i++];
    }
    if(j == 0)
        str[j++] = '0';
    // Null-terminate the string
    str[j] = '\0';

}