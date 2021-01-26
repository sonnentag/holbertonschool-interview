#!/usr/bin/python3

import sys

codes = {}
count = 0
size = 0

try:
    for line in sys.stdin:
        count += 1
        code = line.split()[-2]
        size += int(line.split()[-1])
        codes[code] = codes.get(code, 0) + 1
        if count == 10:
            for k, v in sorted(codes.items(), key=lambda x: x[0]):
                print("{}: {}".format(k, v))
            print("File size: {}".format(size))
            count = 0

except KeyboardInterrupt:
    for k, v in sorted(codes.items(), key=lambda x: x[0]):
        print("{}: {}".format(k, v))
    print("File size: {}".format(size))
