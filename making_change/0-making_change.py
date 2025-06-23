#!/usr/bin/python3
"""Module for makeChange function"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed 
    to meet the given amount total.

    Args:
        coins (list): List of coin values.
        total (int): The total amount to meet.

    Returns:
        int: Fewest number of coins needed to meet total,
             or -1 if it's not possible.
    """
    if total <= 0:
        return 0

    max_val = total + 1
    dp = [max_val] * (total + 1)
    dp[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != max_val else -1
