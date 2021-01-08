#!/usr/bin/python3
""" Task 0. Minimum Operations """


def minOperations(n):
    ''' calculates fewest number of operations needed for desired result '''

    if n <= 1:
        return 0

    for i in range(2, n):
        while (n % i == 0):
            return minOperations(int(n / i)) + i

    return n
