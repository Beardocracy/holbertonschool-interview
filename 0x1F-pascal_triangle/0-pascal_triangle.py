#!/usr/bin/python3
'''
0-pascal_triangle
'''


def pascal_triangle(n):
    '''
    Returns a list of lists of integers representing Pascs triangle of n
    '''
    if n <= 0:
        return []

    array = [[0 for x in range(n)] for y in range(n)]

    for row in range(0, n):
        for i in range(0, row + 1):
            if (i == 0 or i == row):
                array[row][i] = 1
            else:
                array[row][i] = (array[row - 1][i - 1] + array[row - 1][i])

    for row in array:
        while 0 in row:
            row.pop(len(row) - 1)

    return array
