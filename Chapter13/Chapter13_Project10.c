#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LEN 50

void reverse_name(char* name)
{
	int i = 0;
	char user_input;
	char initial = '0';
	bool initial_not_reached = true;
	bool last_name_not_reached = true;
	bool print_last = false;

	do
	{
		user_input = name[i];

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
		i++;

	} while (i < strlen(name));

	printf(" %c.", initial);

}

int main(void)
{

	char user_input[MAX_INPUT_LEN];
	printf("Enter first and last name: ");
	gets(user_input);

	reverse_name(user_input);
}