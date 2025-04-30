# Heap Sort Algorithm

## Overview

This project implements the Heap Sort algorithm to sort an array of integers in ascending order. It uses the **sift-down** method to build a max heap and sorts the array in-place. The program outputs the array after each swap to allow for better understanding of the sorting process.

## File Structure

- `0-heap_sort.c`: Contains the implementation of the heap sort algorithm.
- `print_array.c`: Defines a function to print the array after each operation.
- `sort.h`: Header file containing function prototypes and necessary includes.
- `0-O`: File containing the time complexity analysis of the heap sort algorithm.

## Algorithm

1. **Sift Down**: Moves the element at a given index down to its correct position in the heap.
2. **Heapify**: Builds a max heap from the given array.
3. **Heap Sort**: Sorts the array by repeatedly swapping the root of the heap with the last element and restoring the heap property.

## Time Complexity

- **Best case**: `O(n)` – If the array is already a heap, the algorithm will only need to sift down once.
- **Average case**: `O(n log n)` – For most unsorted arrays, building the heap and performing the swaps requires O(log n) operations for each of the n elements.
- **Worst case**: `O(n log n)` – Even in the worst case, the algorithm performs at most O(log n) work for each of the n elements.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/holbertonschool-interview.git
