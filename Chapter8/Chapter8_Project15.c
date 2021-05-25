#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// get the key
	int key = 0;
	printf("Insert key: ");
	scanf("%d", &key);
	// clear newline from buffer
	getchar();

	// get the plaintext
	const int max_length = 80;
	int message_length = -1;
	char message[80]; char input;
	char ciphertext[80];

	printf("Enter message (max 80 characters):\n>> ");
	do
	{
		input = getchar();
		message_length += 1;
		message[message_length] = input;
	} while (input != '\n');

	for (int i = 0; i < message_length; i++)
	{
		// printf("%c", message[i]);
		ciphertext[i] = message[i];
	}
	printf(" message length: %d\n",message_length);


	// convert to ciphertext
	// ci = (pi + k) % 26
	for (int i = 0; i < message_length; i++)
	{
		// check if lowercase or uppercase letter
		if (isalpha(ciphertext[i]) != 0)
		{
			// uppercase
			if (isupper(ciphertext[i]))
			{
				ciphertext[i] = (((ciphertext[i] - 'A') + key) % 26) + 'A';
			}
			// lowercase
			if (islower(ciphertext[i]))
			{
				ciphertext[i] = (((ciphertext[i] - 'a') + key) % 26) + 'a';
			}
		}
	}

	// print ciphertext
	for (int i = 0; i < message_length; i++)
	{
		printf("%c", ciphertext[i]);
	}
}