#!/usr/bin/python3
""" a function that returns the perimeter of the island
"""


def island_perimeter(grid):
    ''' grid is a list of list of integers
      - 0 represents water, 1 represents land
      - the entire grid is surrounded by water
    '''
    p = 0
    for r in range(len(grid)):
        for c in range(len(grid[r])):
            if grid[r][c] == 1:
                ''' add left and right at end of row '''
                if (grid[r][c + 1] == 0):
                    p += 2
                ''' add top and bottom at end of column '''
                if (grid[r + 1][c] == 0):
                    p += 2
    return p
