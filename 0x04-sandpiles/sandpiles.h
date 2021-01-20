#ifndef _SANDPILES_H
#define _SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple(int grid[3][3], int map);
int checkgrid(int grid[3][3]);
int mapgrid(int grid[3][3]);

#endif /* _SANDPILES_H */
