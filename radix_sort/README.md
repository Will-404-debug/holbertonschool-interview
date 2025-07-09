# Radix Sort Implementation in C

## Project Description

This project implements the Radix Sort algorithm to sort an array of integers in ascending order. The Radix Sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. This implementation uses the Least Significant Digit (LSD) method of Radix Sort, where sorting starts from the least significant digit to the most significant digit.

## Features and Concepts Implemented

- **Radix Sort Algorithm**: Implements the LSD radix sort algorithm.
- **Dynamic Memory Allocation**: Utilizes `malloc` and `free` for dynamic memory management.
- **Counting Sort**: Uses counting sort as a subroutine to sort digits at each significant position.
- **Utility Function**: Includes a utility function to find the maximum value in the array.
- **Digit-by-Digit Processing**: Processes each digit of the numbers starting from the least significant digit.
- **Array Printing**: Prints the array each time the significant digit is increased to show the progress of sorting.
