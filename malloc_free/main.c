#include "main.h"
#include <stdio.h>
#include <stdlib.h>  // Include this line for free()

int main(void)
{
    int **grid;
    int height = 3, width = 4;
    int i, j;

    grid = alloc_grid(width, height);
    if (grid == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    /* Print the grid */
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

    /* Free the grid */
    for (i = 0; i < height; i++)
        free(grid[i]);
    free(grid);

    return (0);
}
