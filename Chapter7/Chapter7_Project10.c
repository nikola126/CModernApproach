#include <stdio.h>
#include <ctype.h>

int main()
{
	char input_char;
	int vowels = 0;

	do
	{
		input_char = getchar();
		input_char = tolower(input_char);

		// count vowels
		if (input_char == 'a' || input_char == 'e' || input_char == 'i' || input_char == 'o' || input_char == 'u')
			vowels += 1;

	} 
	while (input_char != '\n');

	printf("Your sentence contains %d vowels.\n", vowels);
}