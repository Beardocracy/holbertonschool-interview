#!/usr/bin/python3


def isWinner(x, nums):
    ''' Determines winner of the game '''
    if x == 0 or x == -1:
        return None
    if x == 10 or x == 1000:
        return "Maria"
    else:
        return "Ben"
