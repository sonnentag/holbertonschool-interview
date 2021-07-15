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
                ''' add 4 sides by default '''
                p += 4
                ''' remove left and right until end of row '''
                if (c + 1 < len(grid[r]) and grid[r][c + 1] == 1):
                    p -= 2
                ''' remove top and bottom until end of column '''
                if (r + 1 < len(grid) and grid[r + 1][c] == 1):
                    p -= 2
    return p
