#include <stdio.h>
#ifndef WORD_H
#define WORD_H

int read_char(FILE *fp_in);

void read_word(char *word, int len, FILE *fp_in);

#endif