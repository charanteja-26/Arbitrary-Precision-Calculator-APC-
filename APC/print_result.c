#include "apc.h"


extern int sign_flag;
void print_result(Dlist *head)
{
    /* Checking if the list is empty */
    if (head == NULL)
    {
        printf("INFO : List is empty\n");
    }
    else
    {
        printf(CYAN);
        printf("Result : ");
        if (sign_flag)
            printf("-");

        int zero_flag = 1;  /* Flag to check leading zeros */

        while (head)
        {
            /* Skip leading zeros */
            if (zero_flag && head->data == 0)
            {
                head = head->next;
                continue;
            }
            zero_flag = 0;  /* Once we encounter a non-zero, set the flag to 0 */

            /* Printing the list */
            printf("%d", head->data);

            /* Traversing in forward direction */
            head = head->next;
        }

        if (zero_flag)
        {
            /* If all are zeros, print single zero */
            printf("0");
        }

        printf("\n");
        printf(RESET);
        sign_flag = 0;
    }
}

