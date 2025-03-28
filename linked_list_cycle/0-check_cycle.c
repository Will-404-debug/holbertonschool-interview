#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 * @list: Pointer to the head of the linked list
 *
 * Return: 1 if there is a cycle, 0 if there is no cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list, *fast = list;

    if (list == NULL)
        return (0);

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return (1); /* Cycle detected */
    }

    return (0); /* No cycle */
}
