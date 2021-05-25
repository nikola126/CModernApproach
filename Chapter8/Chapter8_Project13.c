#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char user_input;
	char initial = '0';
	bool initial_not_reached = true;
	bool last_name_not_reached = true;
	bool print_last = false;
	char last_name_arr[20];
	int last_name_arr_index = 0;

	do
	{
		user_input = getchar();

		// skip spaces to get to initial
		if (isalpha(user_input) && initial_not_reached)
		{
			initial = user_input;
			initial_not_reached = false;
		}

		// skip spaces until last name
		if (!isalpha(user_input) && !initial_not_reached)
		{
			last_name_not_reached = false;
			print_last = true;
		}

		if (print_last == true)
		{
			// avoid new line chars
			if (isalpha(user_input))
			{
				last_name_arr[last_name_arr_index] = user_input;
				last_name_arr_index += 1;
				// add chars to last name array
			}

		}

	} while (user_input != '\n');

	for (int i = 0; i < last_name_arr_index; i++)
	{
		printf("%c", last_name_arr[i]);
	}
	printf(", %c", initial);
}