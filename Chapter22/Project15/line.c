#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0)
    {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(FILE *fp_out)
{
    int extra_spaces, spaces_to_insert, i, j;

    bool alternate_spacing = true;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++)
    {
        if (line[i] != ' ')
            putc(line[i], fp_out);
        else
        {
            spaces_to_insert = extra_spaces / (num_words - 1);

            // switch spacing here
            if (extra_spaces && alternate_spacing)
            {
                spaces_to_insert += 1;
                alternate_spacing = !alternate_spacing;
            }

            for (j = 1; j <= spaces_to_insert + 1; j++)
                putc(' ', fp_out);
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(FILE *fp_out)
{
    if (line_len > 0)
        fputs(line, fp_out);
}