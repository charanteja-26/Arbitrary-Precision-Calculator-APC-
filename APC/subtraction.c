#include "apc.h"


/*subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // Initialize pointers for traversing the input lists
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    unsigned int borrow = 0, borrow_flag = 0;

    // Iterate through both lists and perform subtraction
    while (temp1 != NULL || temp2 != NULL)
    {
        int data1 = 0;
        int data2 = 0;

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

        data1 = data1 - borrow;
        // Perform subtraction with borrow
        if (data1 < data2)
        {
            data1 += 10;
            borrow_flag = 1;

        }
        else
        {
            borrow_flag = 0;
        }

        int res = data1 - data2;
        borrow = borrow_flag;

        // Insert the result at the beginning of the result list
        insert_at_first(headR, tailR, res);
    }
        
    return SUCCESS;
}

