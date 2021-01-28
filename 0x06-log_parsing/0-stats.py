#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""
import sys


try:
    i = 0
    my_dict = {
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
    for l in sys.stdin:
        w = l.split()
        if len(w) >= 2:
            if w[-2] in my_dict.keys():
                my_dict[w[-2]] += 1
            fileSize += int(w[-1])
            i += 1
            if not i % 10:
                print("File size: {:d}".format(fileSize))
                for key in sorted(my_dict.keys()):
                    if my_dict[key] != 0:
                        print("{}: {:d}".format(key, my_dict[key]))
    print("File size: {:d}".format(fileSize))
    for key in sorted(my_dict.keys()):
        if my_dict[key] != 0:
            print("{}: {:d}".format(key, my_dict[key]))
except KeyboardInterrupt:
    print("File size: {:d}".format(fileSize))
    for key in sorted(my_dict.keys()):
        if my_dict[key] != 0:
            print("{}: {:d}".format(key, my_dict[key]))
    raise
