#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""
import sys


try:
    i = 0
    status = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }
    fileSize = 0
    for line in sys.stdin:
        words = line.split()
        if len(words) >= 2:
            if words[-2] in status.keys():
                status[words[-2]] += 1
            fileSize += int(words[-1])
            i += 1
            if not i % 10:
                print("File size: {:d}".format(fileSize))
                for key in sorted(status.keys()):
                    if status[key] != 0:
                        print("{}: {:d}".format(key, status[key]))
    print("File size: {:d}".format(fileSize))
    for key in sorted(status.keys()):
        if status[key] != 0:
            print("{}: {:d}".format(key, status[key]))
except KeyboardInterrupt:
    print("File size: {:d}".format(fileSize))
    for key in sorted(status.keys()):
        if status[key] != 0:
            print("{}: {:d}".format(key, status[key]))
    raise
