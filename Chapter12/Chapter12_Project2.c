#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 100

void palindrome_message_int()
{
    char message[MAX_LEN];
    char c;
    int mes_len = 0;
    printf("Enter a message: \n");
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        if (mes_len >= MAX_LEN)
            break;
        message[mes_len] = c;
        mes_len += 1;
    }

    // removes spaces and punctuation
    // transforms to lowercase
    char clean[MAX_LEN];
    int j = 0; int clean_len = 0;
    for (int i = 0; i < mes_len; i++)
    {
        if (isalpha(message[i]))
        {
            clean[j] = tolower(message[i]);
            j++;
        }
    }
    clean_len = j-1;

    // checks for palindrome
    for (int i = 0; i <= clean_len/2; i++)
    {
        if (clean[i] != clean[clean_len-i])
        {
            printf("Not a palindrome!\n");
            return;
        }
    }
    printf("It's a palindrome!\n");
}

void palindrome_message_pointer()
{
    char message[MAX_LEN];
    char c;
    int mes_len = 0;
    printf("Enter a message: \n");
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        if (mes_len >= MAX_LEN)
            break;
        message[mes_len] = c;
        mes_len += 1;
    }

    // removes spaces and punctuation
    // transforms to lowercase
    char clean[MAX_LEN];
    int j = 0; int clean_len = 0;
    for (int i = 0; i < mes_len; i++)
    {
        if (isalpha(message[i]))
        {
            clean[j] = tolower(message[i]);
            j++;
        }
    }
    clean_len = j-1;

    // checks for palindrome
	char* start_to_end = clean;
	char* end_to_start;

	for (end_to_start = clean + clean_len; end_to_start >= clean; end_to_start--)
	{
		//printf("From End: %c\tFrom Start: %c\n", *end_to_start, *start_to_end);
		if (*end_to_start != *start_to_end)
		{
            printf("Not a palindrome!\n");
            return;
		}
		start_to_end++;
	}
    printf("It's a palindrome!\n");
}

int main()
{
    palindrome_message_int();
    palindrome_message_pointer();
}