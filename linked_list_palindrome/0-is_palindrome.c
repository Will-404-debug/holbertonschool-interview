#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 * Return: Pointer to the new head (reversed list)
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to pointer of the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *reversed;
    
    if (*head == NULL || (*head)->next == NULL) /* Empty list or single node */
        return (1);

    /* Find middle using slow and fast pointer */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half of the list */
    reversed = reverse_list(slow);
    second_half = reversed;

    /* Compare first and second half */
    slow = *head;
    while (reversed)
    {
        if (slow->n != reversed->n)
        {
            reverse_list(second_half); /* Restore original list */
            return (0);
        }
        slow = slow->next;
        reversed = reversed->next;
    }

    /* Restore original list */
    reverse_list(second_half);
    return (1);
}
