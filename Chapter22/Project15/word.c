#include <stdio.h>
#include <string.h>
#include "word.h"

int read_char(FILE *fp_in)
{
    int ch = getc(fp_in);

    if (ch == '\n' || ch == '\t')
        // ignores new lines or tabs in source file
        return ' ';
    return ch;
}

void read_word(char *word, int len, FILE *fp_in)
{
    int ch, pos = 0;
    while ((ch = read_char(fp_in)) == ' ')
        // skip spaces, stop at non-blank characters or EOF
        ;
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
            // stores characters until max length
            word[pos++] = ch;
        if (pos == len)
            word[pos] = '*';
        ch = read_char(fp_in);
    }
    // terminate string
    word[pos] = '\0';
}