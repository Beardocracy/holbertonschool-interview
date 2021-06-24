#!/usr/bin/python3
''' Determine the fewest number of coins needed to meet a given total '''


def makeChange(coins, total):
    ''' Find the least number of coins needed '''
    if (total <= 0):
        return (0)

    coins.sort(reverse=True)
    coins_total = 0

    for coin_value in coins:
        times_coin_goes_into_total = total // coin_value
        if (times_coin_goes_into_total > 0):
            coins_total += times_coin_goes_into_total
            total = total % coin_value

    if (total == 0):
        return (coins_total)
    return (-1)
