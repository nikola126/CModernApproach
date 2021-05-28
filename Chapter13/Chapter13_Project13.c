#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

void encrypt(char *message, int shift)
{
	// get the key
	int key = shift;

	int message_length = strlen(message);

	// convert to ciphertext
	// ci = (pi + k) % 26
	for (int i = 0; i < message_length; i++)
	{
		// check if lowercase or uppercase letter
		if (isalpha(message[i]) != 0)
		{
			// uppercase
			if (isupper(message[i]))
				message[i] = (((message[i] - 'A') + key) % 26) + 'A';

			// lowercase
			if (islower(message[i]))
				message[i] = (((message[i] - 'a') + key) % 26) + 'a';
		}
	}

	// print ciphertext
	printf("Encrypted Text: \n");
	for (int i = 0; i < message_length; i++)
	{
		printf("%c", message[i]);
	}
	printf("\n");
}

int main()
{
	char user_text[MAX_SENTENCE_LENGTH];
	int key = 0;

	printf("Enter sentence to be encrypted:");
	gets(user_text);
	printf("Enter encryption key: ");
	scanf("%d", &key);

	encrypt(user_text, key);
}