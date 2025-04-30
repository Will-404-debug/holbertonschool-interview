#include "sort.h"

/**
 * sift_down - Moves the element at index i down to its correct position
 * @array: The array to be sorted
 * @size: The size of the array
 * @i: The index of the element to move
 * @swaps: Keeps track of the number of swaps
 */
void sift_down(int *array, size_t size, size_t i, size_t *swaps)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    size_t temp;

    // Ensure left and right indices are within bounds
    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    // If largest is not the current index, swap and continue
    if (largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        (*swaps)++;
        print_array(array, size);  // Print array after each swap
        sift_down(array, size, largest, swaps);  // Recurse
    }
}

/**
 * heapify - Builds a max heap from an unsorted array
 * @array: The array to be heapified
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    size_t i;
    size_t swaps = 0;

    for (i = size / 2; i > 0; i--)
        sift_down(array, size, i - 1, &swaps);
    sift_down(array, size, i - 1, &swaps);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;
    size_t temp;

    heapify(array, size);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);  // Print array after each swap
        sift_down(array, i, 0, &i);
    }
}
