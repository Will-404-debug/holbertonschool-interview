# Slide Line - 2048 Game Mechanic

## Description

This project implements a simplified version of the popular 2048 game mechanic, but on a single horizontal line. The goal is to slide and merge numbers in an array of integers either to the left or to the right, following the rules of the 2048 game:
- Identical numbers, if adjacent or separated by zeros, are merged.
- After merging, the array is shifted again to remove any zeros between non-zero numbers.

The project contains a function `slide_line()` that performs these operations based on the specified direction.

## Function Prototype

```c
int slide_line(int *line, size_t size, int direction);
