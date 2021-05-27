#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix, rotate it 90 degrees clockwise"""
    le = len(matrix[0]) - 1
    for i in range(le // 2):
        for j in range(i, le - i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[le - j][i]
            matrix[le - j][i] = matrix[le - i][le - j]
            matrix[le - i][le - j] = matrix[j][le - i]
            matrix[j][le - i] = temp
