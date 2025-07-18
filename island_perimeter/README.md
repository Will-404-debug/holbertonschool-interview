# Island Perimeter Calculation

## Project Description

This project involves writing a function `island_perimeter(grid)` that calculates the perimeter of an island represented in a grid. The grid is a list of lists of integers where `0` represents water and `1` represents land. The function computes the perimeter by analyzing the grid and counting the edges of the land cells that contribute to the perimeter.

## Features and Concepts Implemented

- **Grid Representation**: The island and water are represented using a 2D grid where `1` represents land and `0` represents water.
- **Grid Analysis**: The function traverses the grid to calculate the perimeter of the island based on the cells' connections.
- **Boundary Conditions**: The function accounts for cells at the boundaries of the grid and cells surrounded by water.
- **Algorithm Efficiency**: The function is designed to efficiently handle grids of up to 100x100 dimensions.
