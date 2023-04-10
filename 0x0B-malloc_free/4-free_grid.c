#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees a 2 dimentional grid by alloc_grid finction
 * @grid: pointer to the 2 dimensional grid
 * @height: height of the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
int i;
for (i = 0; i < height; i++)
free(grid[i]);
free(grid);
}
