#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // Initialize pointers for traversing the input lists
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    unsigned int carry = 0, res;

    // Iterate through both lists and carry
    while (temp1 != NULL || temp2 != NULL || carry)
    {
        unsigned int data1 = 0;
        unsigned int data2 = 0;

        // If temp1 is not null, set data1 to temp1's data and move to the previous node
        if (temp1 != NULL)
        {
            data1 = temp1->data;
            temp1 = temp1->prev;
        }
        
        // If temp2 is not null, set data2 to temp2's data and move to the previous node
        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }

        // Calculate the sum of the current digits and the carry
        res = data1 + data2 + carry;
        carry = res / 10; // Update the carry
        res = res % 10; // Get the digit to insert into the result list
        insert_at_first(headR, tailR, res); // Insert the result at the beginning of the result list
    }

    // Print the resulting list
   // print_result(*headR);
    
    return SUCCESS; 
}
