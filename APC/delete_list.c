#include "apc.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
    {
        return FAILURE; // List is empty
    }

    Dlist *temp;

    // Traverse the list and free each node
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;

    return SUCCESS; 
}
