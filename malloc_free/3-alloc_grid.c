#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to the 2D array or NULL if failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h, w;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for the array of row pointers */
	grid = (int **)malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	/* Allocate memory for each row and initialize values to 0 */
	for (h = 0; h < height; h++)
	{
		grid[h] = (int *)malloc(sizeof(int) * width);
		if (grid[h] == NULL)
		{
			/* Free previously allocated memory in case of failure */
			for (w = 0; w < h; w++)
				free(grid[w]);
			free(grid);
			return (NULL);
		}
		for (w = 0; w < width; w++)
			grid[h][w] = 0;
	}

	return (grid);
}
