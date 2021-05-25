#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	const int max_size = 5;
	const int arr_x_size = max_size;
	const int arr_y_size = max_size;
	char arr[arr_x_size][arr_y_size];
	bool path_available = true;
	bool letter_not_placed = true;

	// print array
	for (int i = 0; i < arr_x_size; i++)
	{
		for (int j = 0; j < arr_y_size; j++)
		{
			arr[i][j] = '.';
			printf("%c\t", arr[i][j]);
		}
		printf("\n");
	}

	srand((unsigned)time(NULL));
	int i = 0, j = 0;
	int direction = 0;
	int destination_x = 0;
	int destination_y = 0;
	int attempts_left = 4;

	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int alphabet_index = 1; int end_index = sizeof(alphabet);

	arr[0][0] = 'a';



	// loop through array until no possible placement or all letters are placed
	while (alphabet_index < end_index || attempts_left > 0 || path_available)
	{
		if (attempts_left <= 0)
		{
			break;
		}
		if (alphabet_index == end_index)
		{
			// printf("Z placed. END\n");
			break;
		}


		// get direction
		direction = rand() % 4;
		//printf("Direction: %d\n", direction);

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
			//printf("Checking UP at [i-1][j] = [%d][%d]\n", destination_x, destination_y);
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				//printf("OUT OF BOUNDS!\n");
				attempts_left--;
				// printf("Attempts left: %d\n", attempts_left);
				// fall through if there are unchecked directions
				if (attempts_left <= 0)
				{
					// printf("No attempts left!\n");
					path_available = false;
					break;
				}
			}
			else
			{
				//printf("IN BOUNDS!\n");
				if (isalpha(arr[destination_x][destination_y]))
				{
					//printf("SPOT ALREADY FILLED!\n");
					attempts_left--;
					// printf("Attempts left: %d\n", attempts_left);
					// fall through if there are unchecked directions
					if (attempts_left <= 0)
					{
						// printf("No attempts left!\n");
						path_available = false;
						break;
					}
				}
				else
				{
					// printf("\t%c placed at [%d][%d]\n", alphabet[alphabet_index], destination_x, destination_y);
					arr[destination_x][destination_y] = alphabet[alphabet_index];
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
			// check if coords are out of bounds
			destination_x = i;
			destination_y = j - 1;
			// printf("Checking LEFT at [i-1][j] = [%d][%d]\n", destination_x, destination_y);
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				// printf("OUT OF BOUNDS!\n");
				attempts_left--;
				// printf("Attempts left: %d\n", attempts_left);
				// fall through if there are unchecked directions
				if (attempts_left <= 0)
				{
					// printf("No attempts left!\n");
					path_available = false;
					break;
				}
			}
			else
			{
				//printf("IN BOUNDS!\n");
				if (isalpha(arr[destination_x][destination_y]))
				{
					// printf("SPOT ALREADY FILLED!\n");
					attempts_left--;
					// printf("Attempts left: %d\n", attempts_left);
					// fall through if there are unchecked directions
					if (attempts_left <= 0)
					{
						// printf("No attempts left!\n");
						path_available = false;
						break;
					}
				}
				else
				{
					// printf("\t%c placed at [%d][%d]\n", alphabet[alphabet_index], destination_x, destination_y);
					arr[destination_x][destination_y] = alphabet[alphabet_index];
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
			// check if coords are out of bounds
			destination_x = i;
			destination_y = j + 1;
			// printf("Checking RIGHT at [i-1][j] = [%d][%d]\n", destination_x, destination_y);
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				// printf("OUT OF BOUNDS!\n");
				attempts_left--;
				// printf("Attempts left: %d\n", attempts_left);
				// fall through if there are unchecked directions
				if (attempts_left <= 0)
				{
					// printf("No attempts left!\n");
					path_available = false;
					break;
				}
			}
			else
			{
				//printf("IN BOUNDS!\n");
				if (isalpha(arr[destination_x][destination_y]))
				{
					// printf("SPOT ALREADY FILLED!\n");
					attempts_left--;
					// printf("Attempts left: %d\n", attempts_left);
					// fall through if there are unchecked directions
					if (attempts_left <= 0)
					{
						printf("No attempts left!\n");
						path_available = false;
						break;
					}
				}
				else
				{
					// printf("\t%c placed at [%d][%d]\n", alphabet[alphabet_index], destination_x, destination_y);
					arr[destination_x][destination_y] = alphabet[alphabet_index];
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
			// check if coords are out of bounds
			destination_x = i + 1;
			destination_y = j;
			// printf("Checking DOWN at [i-1][j] = [%d][%d]\n", destination_x, destination_y);
			if (destination_x < 0 || destination_x >= max_size || destination_y < 0 || destination_y >= max_size)
			{
				// printf("OUT OF BOUNDS!\n");
				attempts_left--;
				// printf("Attempts left: %d\n", attempts_left);
				// fall through if there are unchecked directions
				if (attempts_left <= 0)
				{
					// printf("No attempts left!\n");
					path_available = false;
					break;
				}
			}
			else
			{
				//printf("IN BOUNDS!\n");
				if (isalpha(arr[destination_x][destination_y]))
				{
					// printf("SPOT ALREADY FILLED!\n");
					attempts_left--;
					// printf("Attempts left: %d\n", attempts_left);
					// fall through if there are unchecked directions
					if (attempts_left <= 0)
					{
						// printf("No attempts left!\n");
						path_available = false;
						break;
					}
				}
				else
				{
					// printf("\t%c placed at [%d][%d]\n", alphabet[alphabet_index], destination_x, destination_y);
					arr[destination_x][destination_y] = alphabet[alphabet_index];
					alphabet_index++;
					letter_not_placed = false;
					i = destination_x;
					j = destination_y;
					attempts_left = 4;
					break;
				}
			}
		default:
			// printf("Reached DEFAULT\n");
			goto go_here_from_default_case;
			if (attempts_left <= 0)
			{
				printf("No attempts left!\n");
				path_available = false;
				break;
			}
			break;
		}	
	}

	// print array
	for (int i = 0; i < arr_x_size; i++)
	{
		for (int j = 0; j < arr_y_size; j++)
		{
			printf("%c\t", arr[i][j]);
		}
		printf("\n");
	}

}