# Making Change

This project contains a Python implementation to determine the fewest number of coins needed to meet a given total amount.

## Task

Write a function `makeChange(coins, total)` that returns the minimum number of coins needed to make change for a given `total`.

### Requirements
- If `total` is 0 or less, return 0.
- If it’s not possible to make change, return -1.
- You have an infinite supply of each coin in the given list.

### Example

```python
makeChange([1, 2, 25], 37)
# Output: 7
