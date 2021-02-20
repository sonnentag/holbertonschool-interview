#!/usr/bin/python3
""" validate whether bytes are utf-8 encoded """


def validUTF8(data):
    ''' return true or false '''

    count = 0
    for d in data:
        if not count:
            count = sigBits(d)
            if count == 0:
                continue
            if count == 1 or count > 4:
                return False
            count -= 1
        else:
            count -= 1
            if sigBits(d) != 1:
                return False

    return count == 0


def sigBits(num):
    ''' count ones '''

    count = 0
    for i in range(7, -1, -1):
        if num & (1 << i):
            count += 1
        else:
            break
    return count
