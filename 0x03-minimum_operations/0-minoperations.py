#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """Minimum Operations"""
    sum_op = 0
    while n > 1:
        for i in range(1, round(n / 2)+1):
            if n % i == 0:
                max_div = i
        sum_op += n / max_div
        n = max_div
    return int(round(sum_op))
