#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
	float words = 0;
	float average = 0;
	char input;
	float lengths = 0;
	float current_word_length = 0;
	bool period_reached = false;

	printf("Enter a sentence:\n>>");

	while ((input = getchar()) != '\n' && !period_reached)
	{
		// ignores punctuation marks other than period
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
			// end of sentence has been found
			// add word, calculate average and reset length counter
			period_reached = true;
			printf("Input after period will be ignored.\n");
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
	}

	printf("Words: %.0f\n", words);
	printf("Average word length: %.1f\n", average);
}