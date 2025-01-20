#!/usr/bin/python3
"""
Module to calculate the minimum operations required to achieve n H characters
"""


def minOperations(n):
    """
    Calculate the minimum number of operations to achieve n H characters

    Args:
        n (int): The target number of H characters

    Returns:
        int: Minimum number of operations or 0 if impossible
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
