#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_COUNT 30
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 200

void sentence_reverse(const char *sentence)
{
	char words_array[MAX_WORD_COUNT][MAX_WORD_LENGTH];

	int row = 0;
	int col = 0;
	// loop through sentence
	for (int i = 0; i < strlen(sentence); i++)
	{
		char symbol = sentence[i];
		// at punctuation, switch words (place terminating character and move to next row)
		if (isalpha(symbol) == 0)
		{
			words_array[row][col] = '\0';
			row++;
			col = 0;
		}
		else
		// place letters in the corresponding sentence (row)
		{
			words_array[row][col] = symbol;
			col++;
		}
	}

	printf("Reversed sentence: \n");
	for (int i = row - 1; i >= 0; i--)
	{
		printf("%s ", words_array[i]);
	}
}

int main()
{
	char sentence[MAX_SENTENCE_LENGTH];

	printf("Enter sentence: \n");
	gets(sentence);

	sentence_reverse(sentence);
}