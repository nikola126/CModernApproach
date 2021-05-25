#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int max_length = 100;
	char input, terminating_character = '.';
	char sentence[max_length] = { 0 };
	int i = 0;

	// save sentence
	printf("Enter a sentence: ");
	do
	{
		input = getchar();

		// save terminating character separately
		if (input == '.' || input == '!' || input == '?')
		{
			terminating_character = input;
		}
		else
		{
			sentence[i] = input;
			i++;
		}
	} while (input != '.' && input != '!' && input != '?');

	int sentence_length = i;

	// loop back and print words
	int start_index = 0;
	int end_index = sentence_length - 1;



	for (int i = sentence_length; i >= 0; i--)
	{
		if (sentence[i] == ' ')
		{
			// new word found
			start_index = i+1;
			for (int j = start_index; j <= end_index; j++)
			{
				printf("%c", sentence[j]);
			}
			printf(" ");
			// change start/end indexes
			end_index = i;
		}
	}
	// no spaces left, print from beginning to first space to add the first word
	for (int j = 0; j < end_index; j++)
	{
		printf("%c", sentence[j]);
	}

	// also print the terminating char
	printf("%c\n", terminating_character);
}