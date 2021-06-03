#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "readline.h"

// saves a line in str[], up to [n] characters
// returns the number of characters in line
int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}