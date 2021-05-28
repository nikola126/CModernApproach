#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

double compute_average_word_length(const char *sentence)
{
	double words = 0;
	double average = 0;
	char input;
	double lengths = 0;
	double current_word_length = 0;
	bool period_reached = false;

	int i = 0;

	while ((input = sentence[i]) != '\n' && !period_reached)
	{
		// ignores most punctuation marks!
		switch (input)
		{
		case ' ':
			// new word has been found
			// add word, calculate average and reset length counter
			words += 1;
			lengths += current_word_length;
			average = lengths / words;
			current_word_length = 0;
			break;
		case '.':
		case '?':
		case '!':
			// end of sentence has been found
			// add word, calculate average and reset length counter
			period_reached = true;
			words += 1;
			lengths += current_word_length;
			average = lengths / words;
			current_word_length = 0;
			break;
		default:
			if (!period_reached)
			{
				current_word_length += 1;
			}
			break;
		}

		i++;
	}
	return average;
}

int main()
{
	char user_input[MAX_SENTENCE_LENGTH];

	printf("Enter sentence (max length = %d):\n", MAX_SENTENCE_LENGTH);
	gets(user_input);

	printf("Average word length: %.2f\n", compute_average_word_length(user_input));
}