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
	int map = 0, pos = 1;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];

			if (grid1[x][y] > 3)
				map += (pos << y);
		}
		pos = pos * 10;
	}

	while (map)
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1, map);
		map = mapgrid(grid1);
	}

}

/**
 * topple - topple grid
 * @grid: 3x3 grid
 * @map: mapped grid of positions to topple
 *
 */
void topple(int grid[3][3], int map)
{
	int x, y, b, pos, div = 100;

	for (x = 2; x >= 0; x--)
	{
		for (y = 0; y < 3; y++)
		{
			b = (map / div % 10) >> y;
			b &= 1;
			if (b)
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
			}
		}
		div /= 10;
	}
}

/**
 * mapgrid - map grid cells to topple
 * @grid: 3x3 grid
 * Return: 0 if none to topple, or 3 digit binary repr of cells to topple
 *
 */
int mapgrid(int grid[3][3])
{
	int x = 0, y = 0;
	int map = 0, pos = 1;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
				map += (pos << y);

		pos = pos * 10;
	}

	return (map);
}
