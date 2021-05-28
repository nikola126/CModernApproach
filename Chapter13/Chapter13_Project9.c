#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 50

int compute_vowel_count(char* name)
{
    int vowels = 0;
    int pos = 0;
    char letter;

    while(name[pos] != '\0')
    {
        // convert to lower
        letter = tolower(name[pos]);
        // count vowels
		if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
			vowels += 1;
        
        // increment position
        pos++;
    }
    return vowels;
}

int main()
{
	char input_char;
	int vowels = 0;

    char sentence[MAX_LEN];
    gets(sentence);
    vowels = compute_vowel_count(sentence);
	printf("Your sentence contains %d vowels.\n", vowels);
}