#!/usr/bin/env python3
""" n queens recursive """

import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)


try:
    N = int(sys.argv[1])

except ValueError:
    print("N must be a number")
    sys.exit(1)


if (4 > N):
    print("N must be at least 4")
    sys.exit(1)


board = [[0 for r in range(0, N)] for c in range(0, N)]


def nQueen(board, col):
    ''' recursively place new queen in each column '''

    if col == N:
        solved(board)
        return True

    for row in range(0, N):
        if (isSafe(board, row, col)):
            board[row][col] = 1
            nQueen(board, col + 1)
            board[row][col] = 0

    return False


def isSafe(board, row, col):
    ''' test if placed queen is "in check" '''

    for x in range(0, N):
        if board[row][x] == 1 or board[x][col] == 1:
            return False

    for x in range(0, N):
        for y in range(0, N):
            if (x + y) == (row + col) or (x - y) == (row - col):
                if (board[x][y] == 1):
                    return False

    return True


def solved(board):
    ''' print each queen's position once all cols are solved '''

    queens = []

    for row in range(0, N):
        for col in range(0, N):
            if board[row][col] == 1:
                queens.append([row, col])

    print(queens)


nQueen(board, 0)
