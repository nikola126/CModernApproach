#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int magic_square_size = 10;
	int arr[magic_square_size][magic_square_size] = { 0 };

	int min_int = 1;
	int max_int = magic_square_size * magic_square_size;

	printf("The program creates a magic square of the specified size [%d x %d]\n", magic_square_size, magic_square_size);
	printf("It will arrange inside the numbers between %d and %d\n", min_int, max_int);

	// arange numbers
	int i = 0, j = 0;
	int current_i = 0, current_j = 0;
	int last_i = 0, last_j = 0;

	for (int i = min_int; i <= max_int; i++)
	{
		//printf("Currently placing %d\n", i);
		// first position and get coords
		if (i == min_int)
		{
			current_i = 0;
			current_j = magic_square_size / 2;
			arr[current_i][current_j] = i;
			last_i = current_i; last_j = current_j;
		}
		else
		{
			// move up one row and over one column
			// i --, j ++
			current_i--; current_j++;
			//printf("Next position: [ %d ][ %d ]\t", current_i, current_j);
			// check if out of bounds and wrap around
			if (current_i > magic_square_size - 1)
				current_i = 0;
			if (current_i < 0)
				current_i = magic_square_size - 1;

			if (current_j > magic_square_size - 1)
				current_j = 0;
			if (current_j < 0)
				current_j = magic_square_size - 1;
			//printf("In bounds: [ %d ][ %d ]\n", current_i, current_j);
			
			// check if placed
			if (arr[current_i][current_j] != 0)
			{
				// use the last successful placement to place number directly below it
				current_i = last_i += 1;
				current_j = last_j;

				//printf("Already placed. Will attempt placing at [ %d ][ %d ]\n", current_i, current_j);
				// check if out of bounds
				if (current_i > magic_square_size - 1)
					current_i = 0;
				if (current_i < 0)
					current_i = magic_square_size - 1;

				if (current_j > magic_square_size - 1)
					current_j = 0;
				if (current_j < 0)
					current_j = magic_square_size - 1;

				//printf("After bounds check: Will place at [ %d ][ %d ]\n", current_i, current_j);
				arr[current_i][current_j] = i;

			}
			else
			{
				arr[current_i][current_j] = i;
				last_i = current_i; last_j = current_j;
			}
		}
	}
	
	printf("\n");
	// print square
	for (int i = 0; i < magic_square_size; i++)
	{
		for (int j = 0; j < magic_square_size; j++)
		{
			printf("[ %3d ]", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}