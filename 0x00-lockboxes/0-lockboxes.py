#!/usr/bin/python3
""" determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened."""
    box_opened = [0]
    sum = 1
    for k in box_opened:
        for value in boxes[k]:
            if value not in box_opened and value != k and value < len(boxes):
                sum = sum + 1
                box_opened.append(value)
    if sum == len(boxes):
        return True
    else:
        return False
