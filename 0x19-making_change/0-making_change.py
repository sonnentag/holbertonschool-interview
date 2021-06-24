#!/usr/bin/python3
""" making change """

from math import floor


def makeChange(coins, total):
    ''' make change
    '''
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    count = 0
    if len(coins) > 0:
        while total > coins[-1]:
            for i in coins:
                if i <= total:
                    count += floor(total/i)
                    total = total % i
    if total == 0:
        return count
    else:
        return -1
