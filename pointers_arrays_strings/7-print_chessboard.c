#include "main.h"

/**
 * print_chessboard - Prints an 8x8 chessboard.
 * @a: The chessboard array.
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++) /* Loop through rows */
	{
		for (j = 0; j < 8; j++) /* Loop through columns */
		{
			_putchar(a[i][j]); /* Print each character */
		}
		_putchar('\n'); /* New line after each row */
	}
}
