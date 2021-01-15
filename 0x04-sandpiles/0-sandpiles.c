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

	int x = 0, y = 0, t = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
			if (grid1[x][y] >= 4)
				t = 1;
		}

	while (t == 1)
		t = topple(grid1);

}

/**
 * topple - topple grid
 * @grid: 3x3 grid
 * Return: 1 if grid was unstable
 */
int topple(int grid[3][3])
{
	int x, y, ret = 0;

	printf("=\n");
	print_grid(grid);

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] >= 4)
			{
				grid[x][y] -= 4;

				if (y > 0)
					grid[x][y - 1]++;
				if (y < 2)
					grid[x][y + 1]++;
				if (x > 0)
					grid[x - 1][y]++;
				if (x < 2)
					grid[x + 1][y]++;

				ret = 1;
			}
		}

	return (ret);
}
