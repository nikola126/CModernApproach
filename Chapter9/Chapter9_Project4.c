#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void read_word(int counts[26])
{
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char input; int arr_size = 26;

	printf("Enter a word: ");
	do
	{
		input = getchar();
		if (isalpha(input))
		{
			input = tolower(input);
			// increment counts
			for (int i = 0; i < arr_size; i++)
			{
				if (input == alphabet[i])
					counts[i] += 1;
			}
		}
	} while (input != '\n');
}

bool equal_array(int counts1[26], int counts2[26])
{
	int arr_size = 26;
	// decrement values
	for (int i = 0; i < arr_size; i++)
	{
		if (counts1[i] != counts2[i])
			return false;
	}
	return true;
}

int main()
{
	int counts1[26] = {0};
	int counts2[26] = {0};

	read_word(counts1);
	read_word(counts2);

	if (equal_array(counts1,counts2))
		printf("The two words are anagrams!\n");
	else
		printf("The two words are NOT anagrams!\n");

}