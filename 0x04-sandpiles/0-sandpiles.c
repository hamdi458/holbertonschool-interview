#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * alt_print_grid - print grid
 * @grid1: grid to print
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void add(int grid1[3][3], int  grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * maxg - find the max
 * @grid1: the grid
 * Return: max of the grid
 */
int maxg(int grid1[3][3])
{
	int i, j, max;

    max = grid1[0][0];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > max)
				max = grid1[i][j];
	return (max);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, grid[3][3];

	add(grid1, grid2);
	if (maxg(grid1) > 3)
	{
		printf("=\n");
		print_grid(grid1);
	}
	while (maxg(grid1) > 3)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid[i][j] = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid[i][j] = grid[i][j] - 4;
					if (j - 1 < 3 && j - 1 >= 0)
						grid[i][j - 1] = grid[i][j - 1] + 1;
					if (j + 1 < 3 && j + 1 >= 0)
						grid[i][j + 1] = grid[i][j + 1] + 1;
					if (i - 1 < 3 && i - 1 >= 0)
						grid[i - 1][j] = grid[i - 1][j] + 1;
					if (i + 1 < 3 && i + 1 >= 0)
						grid[i + 1][j] = grid[i + 1][j] + 1;
				}
			}
		}
		if (maxg(grid1) > 3)
		{
			printf("=\n");
			print_grid(grid1);
		}
        add(grid1, grid);
	}
}
