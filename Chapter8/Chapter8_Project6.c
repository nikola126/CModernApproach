#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int message_length = 255;
	char message[message_length] = { ' ' };
	char input;

	printf("Enter message:\n>> ");
	input = getchar(); int i = 0;
	while (input != '\n')
	{
		message[i] = input;
		i++;
		input = getchar();
	}

	// convert text
	for (int j = 0; j < i; j++)
	{
		message[j] = toupper(message[j]);

		switch (message[j])
		{
		case 'A':
			message[j] = '4';
			break;
		case 'B':
			message[j] = '8';
			break;
		case 'E':
			message[j] = '3';
			break;
		case 'I':
			message[j] = '1';
			break;
		case 'O':
			message[j] = '0';
			break;
		case 'S':
			message[j] = '5';
			break;
		default:
			break;
		}
	}

	// append exclamation marks
	int remaining_chars = message_length - i;
	if (remaining_chars > 10)
		remaining_chars = 10;

	for (int j = i+1; j < (i + remaining_chars); j++)
	{
		message[j] = '!';
	}

	printf("In B1FF speak:\n");
	for (int j = 0; j < (i + remaining_chars); j++)
	{
		printf("%c", message[j]);
	}
}