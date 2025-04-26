# Water Trapping Problem

This project solves the water trapping problem where you are given an array of integers representing the heights of walls. The goal is to calculate how much water would be trapped between the walls after it rains.

## Problem Breakdown
- Each element in the array represents a wall of a certain height.
- Water can only be trapped in valleys formed by taller walls on both sides.
- For each position in the array, the amount of water that can be trapped is determined by the shortest of the two tallest walls on either side.

## Approach
1. Calculate the tallest walls on the left and right of each position.
2. The water trapped at each position is the difference between the minimum of the two tallest walls and the height at that position, if positive.

