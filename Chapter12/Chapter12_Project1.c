#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 100

void reverse_message_int()
{
    char message[MAX_LEN];
    char c;
    int current_pos = 0;
    printf("Enter a message: \n");
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        if (current_pos >= MAX_LEN)
            break;
        message[current_pos] = c;
        current_pos += 1;
    }
    for (int i = current_pos - 1; i >= 0; i--)
    {
        printf("%c", message[i]);
    }
    printf("\n");
}

void reverse_message_pointer()
{
    char message[MAX_LEN];
    char c;
    int mes_len = 0;
    char *current_pos;
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

    printf("Using pointer arithmetic: \n");
    for (current_pos = message + mes_len - 1; current_pos >= message; current_pos--)
        printf("%c", *current_pos);
    printf("\n");
}

int main()
{
    reverse_message_int();
    reverse_message_pointer();
}