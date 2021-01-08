#!/usr/bin/python3
"""
This module contains minOperations
"""


def minOperations(n):
    ''' Returns the sum of prime factors of a number'''
    if n <= 0:
        return 0
    total = 0
    divider = 2
    while (n > 1):
        if (n % divider == 0):
            total = total + divider
            n = n / divider
            divider = 2
        else:
            if (divider == 2):
                divider += 1
            else:
                divider += 2
    return total
