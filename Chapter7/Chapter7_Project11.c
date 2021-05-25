#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
	char user_input;
	char initial = '0';
	bool initial_not_reached = true;
	bool last_name_not_reached = true;
	bool print_last = false;

	printf("Enter a first and last name: ");
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
				printf("%c", user_input);

		}

	} while (user_input != '\n');

	printf(", %c.", initial);
}