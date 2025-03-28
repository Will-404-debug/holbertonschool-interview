# Max Binary Heap Implementation

## Description
This project implements a Max Binary Heap in C, adhering to specific coding and style guidelines. A Max Binary Heap is a binary tree where the value of each parent node is greater than or equal to the values of its children, and the tree is complete (all levels are fully filled except possibly the last, which is filled from left to right).

### Features
- Creation of a binary tree node.
- Insertion of values into a Max Binary Heap while maintaining heap properties.
- Utility to visualize the binary tree structure.

## File Structure
heap_insert/
├── binary_trees.h           # Header file with structure and function prototypes
├── 0-binary_tree_node.c     # Function to create a new binary tree node
├── 1-heap_insert.c          # Function to insert values into the Max Binary Heap
├── binary_tree_print.c      # Utility function to visualize the tree
├── 1-main.c                 # Test file for heap insertion

## Functions

### `binary_tree_node`
**Prototype**: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- Creates a new binary tree node.
- Parameters:
  - `parent`: Pointer to the parent node.
  - `value`: Value to store in the new node.
- Returns: Pointer to the new node or `NULL` on failure.

### `heap_insert`
**Prototype**: `heap_t *heap_insert(heap_t **root, int value);`
- Inserts a value into a Max Binary Heap.
- Parameters:
  - `root`: Double pointer to the root node of the heap.
  - `value`: Value to insert.
- Returns: Pointer to the newly inserted node or `NULL` on failure.
- Maintains Max Heap properties using:
  - `heapify_up`: Swaps nodes as necessary to maintain the heap order.
  - `find_insert_position`: Locates the appropriate position for insertion.

### `binary_tree_print`
**Prototype**: `void binary_tree_print(const binary_tree_t *tree);`
- Visualizes the binary tree structure.

## Compilation and Execution

### Compilation
Use the following command to compile the project:
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o heap_insert

Run the program: ./heap_insert

Example Output:
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
