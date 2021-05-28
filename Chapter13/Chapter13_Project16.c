#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 50

void reverse(char *message)
{
    // reverses message using two pointers

    int message_length = strlen(message);
    char from_start = message[0];
    char from_end = message[message_length - 1];
    char swap;

    for (int i = 0; i < (message_length / 2); i++)
    {
        swap = message[i];
        message[i] = message[message_length - 1 - i];
        message[message_length - 1 - i] = swap;
    }
}

int main()
{
    char message[MAX_LENGTH];
    int message_length = 0;

    printf("Enter message: ");
    gets(message);

    reverse(message);

    printf("Reversed message: %s\n", message);
}