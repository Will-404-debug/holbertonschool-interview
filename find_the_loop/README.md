# Find Loop in Linked List

This repository contains the implementation of a function to detect a loop within a singly linked list.

## Project Overview

The purpose of this project is to implement a function that can identify a loop in a linked list where the last node points back to any of the previous nodes instead of pointing to `NULL`. The function is defined as follows:

- **Prototype**: `listint_t *find_listint_loop(listint_t *head);`
- **Returns**: The address of the node where the loop starts, or `NULL` if there is no loop.

The function is constrained by not allowing the use of `malloc`, `free`, or arrays and can only declare a maximum of two variables.