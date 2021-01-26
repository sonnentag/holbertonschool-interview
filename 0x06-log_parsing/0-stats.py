#!/usr/bin/python3
""" format log stats parsed from stdin """

import sys

codes = {}
count = 0
size = 0


def display_stats(codes, size):
    ''' function used to print formatted stats below '''

    print("File size: {}".format(size))
    for k, v in sorted(codes.items(), key=lambda x: x[0]):
        print("{}: {}".format(k, v))


''' expect line ending with: .. <status code> <file size>'''
try:
    for line in sys.stdin:
        count += 1
        ''' <status code> '''
        code = line.split()[-2]
        ''' <file size> '''
        size += int(line.split()[-1])
        ''' increment/add code to dict '''
        codes[code] = codes.get(code, 0) + 1
        if count == 10:
            display_stats(codes, size)
            count = 0

except KeyboardInterrupt:
    display_stats(codes, size)
