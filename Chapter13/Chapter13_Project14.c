#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

bool are_anagrams(const char *word1, const char *word2)
{
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int values[26] = {0};
	int arr_size = sizeof(values) / sizeof(values[0]);
	char input;

	// read first word
	int first_word_length = strlen(word1);
	for (int i = 0; i < first_word_length; i++)
	{
		input = word1[i];
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
	}

	// read second word
	int second_word_length = strlen(word1);
	for (int i = 0; i < second_word_length; i++)
	{
		input = word2[i];
		if (isalpha(input))
		{
			input = tolower(input);
			// decrement values
			for (int i = 0; i < arr_size; i++)
			{
				if (input == alphabet[i])
					values[i] -= 1;
			}
		}
	}

	// loop through values and check if all are zeros
	for (int i = 0; i < arr_size; i++)
	{
		if (values[i] != 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char first_word[MAX_WORD_LENGTH];
	char second_word[MAX_WORD_LENGTH];

	printf("Enter first word: ");
	gets(first_word);
	printf("Enter second word: ");
	gets(second_word);

	if (are_anagrams(first_word, second_word))
		printf("The two words are ANAGRAMS.\n");
	else
		printf("The two words are NOT anagrams.\n");
}