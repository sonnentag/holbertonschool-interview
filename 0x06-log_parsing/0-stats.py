#!/usr/bin/python3
""" format log stats parsed from stdin """


def display_stats(codes, size):
    ''' function used to print formatted stats below '''

    print("File size: {}".format(size))
    for k, v in sorted(codes.items()):
        print("{}: {}".format(k, v))


if __name__ == "__main__":
    ''' expect line ending with: .. <status code> <file size>'''

    import sys

    codes = {}
    count = 0
    size = 0

    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                display_stats(codes, size)
                break
            count += 1
            size += int(line.split()[-1])
            code = line.split()[-2]
            codes[code] = codes.get(code, 0) + 1

            if count == 10:
                display_stats(codes, size)
                count = 0

        except KeyboardInterrupt:
            display_stats(codes, size)
            break
