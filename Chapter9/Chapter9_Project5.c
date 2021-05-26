#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 99

void create_magic_square(int n, int magic_square[MAX_SIZE][MAX_SIZE])
{

	int min_int = 1;
	int max_int = n * n;

	printf("The program creates a magic square of the specified size [%d x %d]\n", n, n);
	printf("It will arrange inside the numbers between %d and %d\n", min_int, max_int);

	// arange numbers
	int i = 0, j = 0;
	int current_row = 0, current_col = 0;
	int last_row = 0, last_col = 0;

	for (int i = min_int; i <= max_int; i++)
	{
		// first position and get coords
		if (i == min_int)
		{
			current_row = 0;
			current_col = n / 2;
			magic_square[current_row][current_col] = i;
			last_row = current_row;
			last_col = current_col;
		}
		else
		{
			// move up one row and over one column
			current_row--;
			current_col++;
			// check if out of bounds and wrap around
			if (current_row > n - 1)
				current_row = 0;
			if (current_row < 0)
				current_row = n - 1;

			if (current_col > n - 1)
				current_col = 0;
			if (current_col < 0)
				current_col = n - 1;

			// check if placed
			if (magic_square[current_row][current_col] != 0)
			{
				// use the last successful placement to place number directly below it
				current_row = last_row += 1;
				current_col = last_col;

				// check if out of bounds
				if (current_row > n - 1)
					current_row = 0;
				if (current_row < 0)
					current_row = n - 1;

				if (current_col > n - 1)
					current_col = 0;
				if (current_col < 0)
					current_col = n - 1;

				magic_square[current_row][current_col] = i;
			}
			else
			{
				// place a number here
				magic_square[current_row][current_col] = i;
				last_row = current_row;
				last_col = current_col;
			}
		}
	}
}

void print_magic_square(int n, int magic_square[MAX_SIZE][MAX_SIZE])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("[ %3d ]", magic_square[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n;
	int magic_square[MAX_SIZE][MAX_SIZE] = {0};
	printf("Enter dimension of magic square (max %d): ", MAX_SIZE);
	scanf("%d", &n);

	create_magic_square(n, magic_square);
	print_magic_square(n, magic_square);
}