#!/usr/bin/python3
''' This module contains rain '''


def rain(walls):
    ''' Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    '''
    size = len(walls) - 1
    left_wall = walls[0]
    prev_index = 0
    bucket = 0

    temp = 0
    for i in range(1, size + 1):
        if (walls[i] >= left_wall):
            left_wall = walls[i]
            prev_index = i
            temp = 0
        else:
            bucket += left_wall - walls[i]
            temp += left_wall - walls[i]
    if (prev_index < size):
        bucket -= temp
        left_wall = walls[size]
        for i in range(size, prev_index - 1, -1):
            if (walls[i] >= left_wall):
                left_wall = walls[i]
            else:
                bucket += left_wall - walls[i]

    return (bucket)
