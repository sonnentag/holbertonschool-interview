#!/usr/bin/python3
""" 0. Rain
"""


def rain(walls):
    """ calculate rainwater retention
    """
    if not walls:
        return 0

    (start, end) = (0, len(walls) - 1)
    (peakL, peakR, total) = (0, 0, 0)

    while start < end:
        ''' if left height is less than right '''
        if walls[start] < walls[end]:
            ''' update the peak if it's below the wall '''
            ''' or else add the difference to the total '''
            if walls[start] >= peakL:
                peakL = walls[start]
            else:
                total += (peakL - walls[start])

            ''' move right one space left '''
            start += 1

        ''' right is more than left '''
        if walls[start] >= walls[end]:
            ''' update the peak if it's below the wall '''
            ''' or else add the difference to the total '''
            if walls[end] >= peakR:
                peakR = walls[end]
            else:
                total += (peakR - walls[end])

            ''' move left one space right '''
            end -= 1

    return total
