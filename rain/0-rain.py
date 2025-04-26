#!/usr/bin/python3

def rain(walls):
        """
        This function calculates the amount of water trapped between walls after rainfall.

        Parameters:
        walls (list): A list of integers where each integer represents the height of a wall.

        Returns:
        int: The total amount of water that can be trapped between the walls.
        """
    if not walls:
        return 0

    # Initialize variables
    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    water = 0

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water trapped
    for i in range(n):
        water += max(0, min(left_max[i], right_max[i]) - walls[i])

    return water

# Example usage
walls1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
walls2 = [4, 2, 0, 3, 2, 5]

print(rain(walls1))  # Output: 6
print(rain(walls2))  # Output: 9

