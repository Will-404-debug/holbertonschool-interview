#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - checks if a given coordinate should be a space
 * @x: x position in the grid
 * @y: y position in the grid
 *
 * Return: 1 if it's a hole, 0 otherwise
 */
int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: sponge level (0 or higher)
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_hole(x, y))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
