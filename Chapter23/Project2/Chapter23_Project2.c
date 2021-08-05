#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    bool letter_reached = false;
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (letter_reached)
            // print letter
            putchar(ch);
        else if (!isspace(ch))
        {
            // space or tab found
            letter_reached = true;
            putchar(ch);
        }
        if (ch == '\n')
            // new line, dont print until a letter is reached
            letter_reached = false;
    }

}