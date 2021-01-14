#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"


/**
 * add - sum of two gride
 * @grid1: grid
 * @grid2: grid
 */
void add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
    {
        j = 0;
        while(j < 3)
        {
            grid1[i][j] += grid2[i][j];
            j++;
        }
    }
			
}
/**
 * print_grid - print gride
 * @grid: the gride
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
 * maxgride - chercher le max de gride
 * @grid1: the grid
 * Return: max
 */
int maxgride(int grid1[3][3])
{
	int i, j, max;

	max = grid1[0][0];
    for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (max < grid1[i][j])
				max = grid1[i][j];
	return (max);
}

/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: grid
 * @grid2: grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, grid[3][3];

	add(grid1, grid2);
	if (maxgride(grid1) > 3)
	{
		printf("=\n");
		print_grid(grid1);
	}
	while (maxgride(grid1) > 3)
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
					grid[i][j] -= 4;
					if (j - 1 < 3 && j - 1 >= 0)
						grid[i][j - 1] += 1;
					if (j + 1 < 3 && j + 1 >= 0)
						grid[i][j + 1] += 1;
					if (i - 1 < 3 && i - 1 >= 0)
						grid[i - 1][j] += 1;
					if (i + 1 < 3 && i + 1 >= 0)
						grid[i + 1][j] += 1;
				}
			}
		}
		add(grid1, grid);
		if (maxgride(grid1) > 3)
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}