#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

int main(void)
{
	int grid1[3][3] = {
		{3, 3, 3},
		{3, 3, 3},
		{3, 3, 3}
	};
	int grid2[3][3] = {
		{1, 3, 1},
		{3, 3, 3},
		{1, 3, 1}
	};

	printf("Initial grids:\n");
	printf("grid1:\n");
	print_grid(grid1);
	printf("grid2:\n");
	print_grid(grid2);

	/* Call sandpiles_sum to compute the result */
	sandpiles_sum(grid1, grid2);

	printf("Final stable grid:\n");
	print_grid(grid1);

	return (EXIT_SUCCESS);
}
