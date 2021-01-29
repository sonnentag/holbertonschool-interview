#!/usr/bin/python3
""" format log stats parsed from stdin """


def display_stats(status, size):
    ''' function used to print formatted stats below '''

    print("File size: {}".format(size))
    for k, v in sorted(status.items()):
        print("{}: {}".format(k, v))


def isint(s):
    ''' helper to test if string is int '''
    try:
        int(s)
        return True
    except ValueError:
        return False


if __name__ == "__main__":
    ''' expect line ending with: .. <status code> <file size>'''

    import sys

    status = {}
    count = 0
    size = 0
    file_size = 0

    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                display_stats(status, size)
                break
            count += 1
            size = line.split()[-1]
            if size != 0 and isint(size):
                code = line.split()[-2]
                status[code] = status.get(code, 0) + 1
                file_size += int(size)

                if count == 10:
                    display_stats(status, size)
                    count = 0

        except KeyboardInterrupt:
            if count >= 1:
                display_stats(status, size)
            break
