#!/usr/bin/python3
""" Task 0. Minimum Operations """


def minOperations(n):
    ''' calculates fewest number of operations needed for desired result '''

    r = 0

    if n > 1:
        for i in range(2, n):
            if (n % i == 0):
                n = n / i
                r += i

    return r
