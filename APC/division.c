#include "apc.h"

// Function to calculate the length of a doubly linked list
unsigned int list_length(Dlist *head)
{
    unsigned int len = 0;
    Dlist *temp = head;

    // Traverse through the list and count the nodes
    while(temp)
    {
        temp = temp->next;
        len++;
    }
    
    return len;
}

// Function to perform division of two large numbers represented by doubly linked lists
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    int count = 1;

    // Loop to perform the division operation
    while (1) {
        // Reset the result list (headR and tailR) for subtraction result
        *headR = *tailR = NULL;

        // Subtract head2 from head1 and store the result in headR
        subtraction(head1, tail1, head2, tail2, headR, tailR);

        int zero_flag = 1;  // Flag to handle leading zeros in the result
        Dlist *headR1 = NULL;
        Dlist *tailR1 = NULL;

        // Copy non-zero digits of headR to headR1
        Dlist *temp1 = *headR;
        while (temp1) {
            // Skip leading zeros
            if (zero_flag && temp1->data == 0) {
                temp1 = temp1->next;
                continue;
            }
            zero_flag = 0;

            // Insert data into headR1
            insert_at_last(&headR1, &tailR1, temp1->data);
            temp1 = temp1->next;
        }

        // Clear head1 and tail1 lists
        dl_delete_list(head1, tail1);

        // Copy headR1 (intermediate result) back to head1
        Dlist *temp = headR1;
        while (temp) {
            insert_at_last(head1, tail1, temp->data);
            temp = temp->next;
        }

        // Clear headR1 and tailR1
        dl_delete_list(&headR1, &tailR1);

        // Get the lengths of the current head1 and head2 lists
        unsigned int list_len1 = list_length(*head1);
        unsigned int list_len2 = list_length(*head2);

        // Check if head1 is smaller or the same size as head2
        if(list_len1 == list_len2)
        {
            // Check if head1 is larger than or equal to head2
            int ret = check_larger(*head1, *head2);
            if(ret)
            {
                break;
            }
        }
        else if(list_len1 < list_len2)
            break;

        count++;
    }

    // Print the result of the division
    printf(CYAN);
    printf("Result : %d\n", count);
    printf(RESET);

    return SUCCESS;
}

// Function to compare two lists to determine which one is larger
int check_larger(Dlist *head1, Dlist *head2)
{
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    // Traverse both lists and compare their data
    while(temp1 != NULL)
    {
        if(temp1->data > temp2->data)
            return 0; // head1 is larger
        if(temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            continue;
        }
        if(temp1->data < temp2->data)
            return 1; // head2 is larger
    }
}
