#!/usr/bin/python3
''' This module contains rain '''


def rain(walls):
    ''' Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    '''
    bucket = 0
    for i in range(len(walls)):
        if i != 0 and walls[i] == 0:
            if walls[i - 1] < walls[i + 1]:
                bucket += walls[i - 1]
            else:
                bucket += walls[i + 1]
    return (bucket)
