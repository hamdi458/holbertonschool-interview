#!/usr/bin/python3
"""Change comes from within
"""


def makeChange(coins, total):
    """
Given a pile of coins of different values,
determine the fewest number of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0
    coins = sorted(coins)
    coins = reversed(coins)
    s = 0
    for i in coins:
        sc = total // i
        total = total - (sc * i)
        s += sc
    if total == 0:
        return s
    return -1
