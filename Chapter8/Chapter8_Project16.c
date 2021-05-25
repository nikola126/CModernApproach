#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int values[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int arr_size = sizeof(values) / sizeof(values[0]);
	char input;

	// read first word
	printf("Enter first word: ");
	do
	{
		input = getchar();
		if (isalpha(input))
		{
			input = tolower(input);
			// increment values
			for (int i = 0; i < arr_size; i++)
			{
				if (input == alphabet[i])
					values[i] += 1;
			}
		}
	} while (input != '\n');
	printf("\n");

	// read second word
	printf("Enter second word: ");
	do
	{
		input = getchar();
		if (isalpha(input))
		{
			input = tolower(input);
			// increment values
			for (int i = 0; i < arr_size; i++)
			{
				if (input == alphabet[i])
					values[i] -= 1;
			}
		}
	} while (input != '\n');
	printf("\n");

	// decrement values
	for (int i = 0; i < arr_size; i++)
	{
		if (values[i] != 0)
		{
			printf("The two words are NOT anagrams.\n");
			return 0;
		}
	}
	printf("The two words are anagrams.\n");
}