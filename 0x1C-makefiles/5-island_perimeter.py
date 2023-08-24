#!/usr/bin/python3
""" Calculate the preimeter of the island """


def island_perimeter(grid):
    """
    Calculates the perimeter if the island described in the grid.
    Args:
    grid (list of list of int): A 2D representing the island.

    Returns:
    int: The preimeter of the island.
    """
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4

                # Check left and up neighbors
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2
                if row > 0 and grid[row - 1][col] ==1:
                    perimeter -= 2

    return perimeter
