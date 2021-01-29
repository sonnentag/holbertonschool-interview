#!/usr/bin/python3
""" format log stats parsed from stdin """


def display_stats(status, size):
    ''' function used to print formatted stats below '''

    print("File size: {}".format(size))
    for k, v in sorted(status.items()):
        print("{}: {}".format(k, v))


if __name__ == "__main__":
    ''' expect line ending with: .. <status code> <file size>'''

    import sys

    status = {}
    count = 0
    file_size = 0

    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                display_stats(status, size)
                break
            count += 1
            size = line.split()[-1]
            code = line.split()[-2]
            if isinstance(size, int):
                status[code] = status.get(code, 0) + 1
                file_size += size

                if count == 10:
                    display_stats(status, size)
                    count = 0

        except KeyboardInterrupt:
            if count >= 1:
                display_stats(status, size)
            break
