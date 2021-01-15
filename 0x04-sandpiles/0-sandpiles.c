#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
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
 * sandpiles_sum - sum grids
 * @grid1: first grid
 * @grid2: second grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	int x = 0, y = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];

	while (checkgrid(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}

}

/**
 * topple - topple grid
 * @grid: 3x3 grid
 *
 */
void topple(int grid[3][3])
{
	int i = 0;
	int xf[] = {1, 0, 0, 2, 2, 0, 1, 1, 2};
	int yf[] = {1, 0, 2, 0, 2, 1, 0, 2, 1};

	for (i = 0; i < 9; i++)
		if (grid[xf[i]][yf[i]] >= 4)
		{
			grid[xf[i]][yf[i]] -= 4;

			if (yf[i] > 0)
				grid[xf[i]][yf[i] - 1]++;
			if (yf[i] < 2)
				grid[xf[i]][yf[i] + 1]++;
			if (xf[i] > 0)
				grid[xf[i] - 1][yf[i]]++;
			if (xf[i] < 2)
				grid[xf[i] + 1][yf[i]]++;
		}
}

/**
 * checkgrid - test if grid is unstable
 * @grid: 3x3 grid
 * Return: 1 is yes, or 0
 *
 */
int checkgrid(int grid[3][3])
{
	int x = 0, y = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
				return (1);

	return (0);
}
