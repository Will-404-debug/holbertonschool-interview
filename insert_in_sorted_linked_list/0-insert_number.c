#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Pointer to the pointer of the first node in the list.
 * @number: the number to insert into the list.
 * 
 * Return: Adress of the new node, or NULL if it failed.
 */ 
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current, *prev;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
    
    new_node->n = number;
    new_node->next = NULL; /* Forgot the equal here*/

    if  (head == NULL || *head == NULL) /* Empty list or invalid input */
    {
        *head = new_node;
        return (new_node);
    }

    current = *head;
    prev = NULL;

    /* Traverse the list to find the insertion point */
    while (current !=NULL && current->n < number)
    {
        prev = current;
        current = current->next;
    }

    /* Insert at the beginning */
    if (prev == NULL)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else /* Insert in the middle or end */
    {
        new_node->next = current;
        prev->next = new_node;
    }

    return (new_node);
}
