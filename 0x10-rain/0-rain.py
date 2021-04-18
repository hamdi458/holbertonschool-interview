#!/usr/bin/python3
"""0x10. Rain"""


def rain(walls):
    """
    Return: Integer indicating total amount of rainwater retained.
    """
    if not walls:
        return 0
    if len(walls) <= 2:
        return 0
    res = 0
    for i in range(1, len(walls) - 1):
        le = max(walls[:i])
        ri = max(walls[i + 1:])
        mini = min(le, ri)
        if walls[i] < mini:
            res += mini - walls[i]
    return res
