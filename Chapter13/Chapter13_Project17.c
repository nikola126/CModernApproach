#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50

bool is_palindrome(const char *message)
{
	int message_length = strlen(message);
	char start_to_end = message[0];
	char end_to_start = message[message_length - 1];

	for (int i = 0; i < message_length / 2; i++)
	{
		start_to_end = message[i];
		end_to_start = message[message_length - 1 - i];

		if (start_to_end != end_to_start)
			return false;
	}
	return true;
}

int main()
{
	char message[MAX_LENGTH];

	printf("Enter message (ignores digits, max length: %d characters) :\n>> ", MAX_LENGTH);
	gets(message);

	if (is_palindrome(message))
		printf("Palindrome!\n");
	else
		printf("Not palindrome!\n");

	return 0;
}