#include "sort.h"
#include <stdlib.h>

/**
 * getMax - A utility function to get the maximum value in an array
 * @array: The array to be examined
 * @size: Number of elements in the array
 *
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - A function to do counting sort of array according to
 * the digit represented by exp
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: Exponent representing the current digit position
 */
void countSort(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output;
	size_t i;
	int digit;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	/* Change count[i] so that it contains actual position */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	/* Copy the output array to array[] */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		countSort(array, size, exp);
}
