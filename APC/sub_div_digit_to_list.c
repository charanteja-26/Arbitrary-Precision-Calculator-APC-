#include "apc.h"

void sub_div_digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *str1, char *str2)
{
    while (*str1 != '\0') 
    {
        insert_at_last(head1, tail1, *str1 - '0'); // Insert the character into the list
        str1++;
    }

    print_list(*head1); // Pass the head of the list to print_list

    while (*str2 != '\0') {
        insert_at_last(head2, tail2, *str2 - '0'); // Insert the character into the list
        str2++;
    }

    print_list(*head2);
}