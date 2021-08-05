#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    char c;
    bool capitalize_next = true;

    // read characters
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            // letter is reached, capitalize it
            // dont capitalize until a non-letter char is found
            if (capitalize_next)
            {
                putchar(toupper(c));
                capitalize_next = false;
            }
            else
            {
                putchar(c);
            }
        }
        else
        {
            // non-letter character
            // print it and capitalize next letter
            putchar(c);
            if (c == ' ' || c == '.' || c == '!' || c == '?')
                capitalize_next = true;
        }
    }
}