#include "apc.h"

int div_validation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]) {
    // Remove leading zeros
    remove_leading_zeros(argv[1]);
    remove_leading_zeros(argv[3]);

    // Check for zero division case
    if (argv[3][0] == '0')
    {
        sub_div_digit_to_list(head1, tail1, head2, tail2, argv[1], argv[3]);
        printf(CYAN"Result : Infinity\n"RESET);
        return 1;
    }

    // Insert digits into linked lists
    char *str1 = argv[1];
    char *str2 = argv[3];
    
    sub_div_digit_to_list(head1, tail1, head2, tail2, str1, str2);
    
    // Compare lists for equal case
    if (list_length(*head1) == list_length(*head2))
    {
        Dlist *temp1 = *head1;
        Dlist *temp2 = *head2;
        int equal = 1;
        while (temp1 != NULL && temp2 != NULL) 
        {
            if (temp1->data < temp2->data)
            {
                printf(CYAN"Result : 0\n"RESET);
                return 1;
            }
            else if (temp1->data > temp2->data)
            {
                equal = 0;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (equal) 
        {
            printf(CYAN"Result : 1\n"RESET);
            return 1;
        }
    }

    // Compare lists for smaller case
    if (list_length(*head1) < list_length(*head2))
    {
        printf(CYAN"Result : 0\n"RESET);
        return 1;
    }

    // Otherwise, the division should proceed
    return SUCCESS;
}
