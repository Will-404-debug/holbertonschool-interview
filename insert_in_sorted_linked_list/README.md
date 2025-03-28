# Insert into a Sorted Singly Linked List

## Description
This project implements a function `insert_node` that inserts a number into a sorted singly linked list. The function ensures that the list remains sorted after the insertion.

## Files
- `0-insert_number.c`: Contains the implementation of the `insert_node` function.
- `lists.h`: Header file with the definition of the `listint_t` structure and function prototypes.
- `linked_lists.c`: Helper functions for testing (e.g., printing, freeing, and adding nodes).
- `0-main.c`: Main file to test the `insert_node` function.

## Function Prototype
```c
listint_t *insert_node(listint_t **head, int number);