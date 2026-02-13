#include "apc.h"

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = new->next = NULL;
    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;

    }
    new->next = *head;
    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}