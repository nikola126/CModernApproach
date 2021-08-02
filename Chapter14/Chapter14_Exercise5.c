#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main()
{
    int i;
    char s[5];

    printf("(a):\n");
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));
    printf("\n");

    printf("(b):\n");
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));

    // i gets incremented repeatedly during macro replacement
    // macro works incorrectly when used with side effects (++)
}