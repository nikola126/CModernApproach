#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char c;

    while ((c = getchar()) != EOF)
    {
        // replace control characters
        if (iscntrl(c))
        {
            // except new line
            if (c == '\n')
                putchar(c);
            else
                putchar('?');
        }
        else
            putchar(c);
    }
}