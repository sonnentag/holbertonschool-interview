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
	int map = 0, pos = 1; /* assign bit to first position */

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];

			if (grid1[x][y] > 3)
				map += (pos << y); /* shift bit y number of places and add to map */
		}
		pos = pos * 10; /* move to next position to insert bits */
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
	int x, y, b, pos = 1;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			b = (map / pos % 10) >> y; /* shift map pos's bits y places right */
			b &= 1; /* capture just the least significant bit */
			if (b == 1)
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
		pos *= 10; /* move working position to the left */
	}
}

/**
 * mapgrid - map grid cells to topple
 * @grid: 3x3 grid
 * Return: number of bits representing 3 rows of cells to topple, or 0 if none
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
				map += (pos << y); /* shift bit y number of places and add to map */

		pos *= 10; /* move to next position to insert bits */
	}

	return (map);
}
