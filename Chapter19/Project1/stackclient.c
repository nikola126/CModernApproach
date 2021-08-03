#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main()
{
    Stack s;
    s = create();

    char user_input;
    char out;
    
    do
    {
        user_input = getchar();
        switch (user_input)
        {
        case '(':
        case '{':
            push(s, user_input);
            break;
        case ')':
            out = pop(s);
            if (out != '(')
            {
                printf("Parentheses NOT nested properly!");
                exit(EXIT_FAILURE);
            }
            break;
        case '}':
            out = pop(s);
            if (out != '{')
            {
                printf("Braces NOT nested properly!");
                exit(EXIT_FAILURE);
            }
            break;
        }
    } while (user_input != '\n');

    if (is_empty(s))
        printf("Parentheses/braces are nested properly.\n");

    return 0;
}