#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    ''' rotate 90 degrees clockwise
    '''
    length = len(matrix) - 1
    for x in range(len(matrix) // 2):
        for y in range(x, len(matrix) - x - 1):
            temp = matrix[y][x]
            ''' print(matrix) '''
            matrix[y][x] = matrix[length - x][y]
            ''' print(matrix) '''
            matrix[length - x][y] = matrix[length - y][length - x]
            ''' print(matrix) '''
            matrix[length - y][length - x] = matrix[x][length - y]
            ''' print(matrix) '''
            matrix[x][length - y] = temp
