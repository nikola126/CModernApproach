#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

void generate_random_walk(char walk[10][10])
{
	const int max_size = 10;
	const int arr_x_size = max_size;
	const int arr_y_size = max_size;
	bool path_available = true;
	bool letter_not_placed = true;

	// initialize array
	for (int i = 0; i < arr_x_size; i++)
		for (int j = 0; j < arr_y_size; j++)
			walk[i][j] = '.';

	srand((unsigned)time(NULL));
	int i = 0, j = 0;
	int direction = 0;
	int destination_x = 0;
	int destination_y = 0;
	int attempts_left = 4;

	char alphabet[] = {'a', 'b', 'c', 'd', 'e',
					   'f', 'g', 'h', 'i', 'j',
					   'k', 'l', 'm', 'n', 'o',
					   'p', 'q', 'r', 's', 't',
					   'u', 'v', 'w', 'x', 'y', 'z'};
	int alphabet_index = 1;
	int end_index = sizeof(alphabet);

	walk[0][0] = 'a';

	// loop through array until no possible placement or all letters are placed
	while (alphabet_index < end_index || attempts_left > 0 || path_available)
	{
		if (attempts_left <= 0)
			break;
		if (alphabet_index == end_index) // all letters placed
			break;

		// get direction
		direction = rand() % 4;

		// check for possible placement
		// if yes -> switch coords and loop again
		// if no -> stop loop

		switch (direction)
		{
		case 0:
		go_here_from_default_case:
			// UP
			// check if coords are out of bounds
			destination_x = i - 1;
			destination_y = j;

			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				// out of bounds
				attempts_left--;
				// fall through if there are unchecked directions
				if (attempts_left <= 0)
				{
					path_available = false;
					break;
				}
			}
			else
			{
				//IN BOUNDS!
				if (isalpha(walk[destination_x][destination_y]))
				{
					//SPOT ALREADY FILLED!
					attempts_left--;
					// fall through if there are unchecked directions
					if (attempts_left <= 0)
					{
						path_available = false;
						break;
					}
				}
				else
				{
					// place letter, reset attempts
					walk[destination_x][destination_y] = alphabet[alphabet_index];
					alphabet_index++;
					letter_not_placed = false;
					i = destination_x;
					j = destination_y;
					attempts_left = 4;
					break;
				}
			}
		case 1:
			// LEFT
			destination_x = i;
			destination_y = j - 1;
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				attempts_left--;
				if (attempts_left <= 0)
				{
					path_available = false;
					break;
				}
			}
			else
			{
				if (isalpha(walk[destination_x][destination_y]))
				{
					attempts_left--;
					if (attempts_left <= 0)
					{
						path_available = false;
						break;
					}
				}
				else
				{
					walk[destination_x][destination_y] = alphabet[alphabet_index];
					alphabet_index++;
					letter_not_placed = false;
					i = destination_x;
					j = destination_y;
					attempts_left = 4;
					break;
				}
			}
		case 2:
			// RIGHT
			destination_x = i;
			destination_y = j + 1;
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				attempts_left--;
				if (attempts_left <= 0)
				{
					path_available = false;
					break;
				}
			}
			else
			{
				if (isalpha(walk[destination_x][destination_y]))
				{
					attempts_left--;
					if (attempts_left <= 0)
					{
						path_available = false;
						break;
					}
				}
				else
				{
					walk[destination_x][destination_y] = alphabet[alphabet_index];
					alphabet_index++;
					letter_not_placed = false;
					i = destination_x;
					j = destination_y;
					attempts_left = 4;
					break;
				}
			}
		case 3:
			// DOWN
			destination_x = i + 1;
			destination_y = j;
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				attempts_left--;
				if (attempts_left <= 0)
				{
					path_available = false;
					break;
				}
			}
			else
			{
				if (isalpha(walk[destination_x][destination_y]))
				{
					attempts_left--;
					if (attempts_left <= 0)
					{
						path_available = false;
						break;
					}
				}
				else
				{
					walk[destination_x][destination_y] = alphabet[alphabet_index];
					alphabet_index++;
					letter_not_placed = false;
					i = destination_x;
					j = destination_y;
					attempts_left = 4;
					break;
				}
			}
		default:
			goto go_here_from_default_case;
			if (attempts_left <= 0)
			{
				path_available = false;
				break;
			}
			break;
		}
	}
}
void print_array(char walk[10][10])
{
	int arr_x_size = 10;
	int arr_y_size = 10;

	// print array
	for (int i = 0; i < arr_x_size; i++)
	{
		for (int j = 0; j < arr_y_size; j++)
		{
			printf("%c ", walk[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char walk[10][10];
	generate_random_walk(walk);
	print_array(walk);
}