#!/usr/bin/python3
""" validate whether bytes are utf-8 encoded """


def validUTF8(data):
    ''' return true or false '''

    count = 0

    ''' for each number provided '''
    for d in data:

        if not count:
            ''' leftmost count of significant bits '''
            count = sigBits(d)

            ''' 0 is first bit in 1 byte sequence '''
            if count == 0:
                continue

            ''' only 2 to 4 are valid '''
            if count == 1 or count > 4:
                return False

            count -= 1

        else:

            ''' decrement until we reach the end '''
            count -= 1

            ''' or bytes no longer begin with 10 '''
            if sigBits(d) != 1:
                return False

    ''' return True if all bits are accounted for '''
    return count == 0


def sigBits(num):
    ''' count down consecutive significant bits from the left '''

    count = 0

    ''' range 7, 6, 5 ... '''
    for i in range(7, -1, -1):

        ''' check to see if our num has a 1 '''
        ''' at i positions to the left '''
        if num & (1 << i):
            count += 1

        else:
            break

    return count
