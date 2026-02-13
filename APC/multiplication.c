#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // Start with the last node of the second list (least significant digit)
    Dlist *temp2 = *tail2;
    int shift_count = 0;

    while (temp2 != NULL)
    {
        // Pointer to traverse the first list (from least significant to most significant digit)
        Dlist *temp1 = *tail1;

        // Temporary result lists for intermediate multiplications
        Dlist *headR2 = NULL;
        Dlist *tailR2 = NULL;

        int carry = 0;
        int data2 = temp2->data;

        while (temp1 != NULL)
        {
            int data1 = temp1->data;
            // Calculate multiplication with carry
            int mul = data1 * data2 + carry;
            carry = mul / 10; // Update carry

            // Insert result at the front of the result list
            if(!shift_count)
                insert_at_first(headR, tailR, mul % 10);
            else
                insert_at_first(&headR2, &tailR2, mul % 10);
            
            // Move to the previous node in the first list
            temp1 = temp1->prev;
        }

        // If there's any remaining carry, add it
        if (carry != 0)
        {
            if(!shift_count)
                insert_at_first(headR, tailR, carry);
            else
                insert_at_first(&headR2, &tailR2, carry);
        }

        // Add zeros at the end for each shift count (for place value adjustment)
        for (int i = 0; i < shift_count; i++)
        {
            insert_at_last(&headR2, &tailR2, 0);
        }

        // Add the intermediate result to the final result
        Dlist *backup_headR = NULL;
        Dlist *backup_tailR = NULL;
        addition(headR, tailR, &headR2, &tailR2 ,&backup_headR, &backup_tailR);

        // Update final result pointers
        *headR = backup_headR;
        *tailR = backup_tailR;

        // Reset temporary result lists
        backup_headR = backup_tailR = NULL;
        headR2 = tailR2 = NULL;

        // Move to the previous node in the second list
        temp2 = temp2->prev;
        shift_count++;
    }

    return 0;
}
