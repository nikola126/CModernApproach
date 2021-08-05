#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

#define MAX_LINE_LENGTH 50

int main(int argc, char *argv[])
{
    FILE *fp_in;

    if (argc != 2)
    {
        fprintf(stderr, "usage: read_phone_number numbers.txt \n");
        exit(EXIT_FAILURE);
    }

    fp_in = fopen(argv[1], "r");
    if (fp_in == NULL)
    {
        fprintf(stderr, "Could not open %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char phone_number[10];
    int digits_read = 0;
    char line[MAX_LINE_LENGTH];
    char next_char;

    while (true)
    {
        // get a line
        fgets(line, MAX_LINE_LENGTH, fp_in);

        // if line is shorter than a phone number, skip it
        if (strlen(line) < 10)
        {
            printf("Incorrect line format!\n");
            break;
        }

        // count and store digits
        for (int i = 0; i < MAX_LINE_LENGTH; i++)
        {
            if (isdigit(line[i]))
            {
                phone_number[digits_read] = line[i];
                digits_read++;
            }
            if (digits_read == 10)
                break;
        }

        // print phone number
        // in standard format: (000) 000-0000
        if (digits_read == 10)
        {
            printf("(%c%c%c) %c%c%c-%c%c%c%c\n", phone_number[0], phone_number[1], phone_number[2], phone_number[3], phone_number[4], phone_number[5], phone_number[6], phone_number[7], phone_number[8], phone_number[9]);
            digits_read = 0;
        }
        else
        {
            printf("Couldn't read phone number.\n");
            digits_read = 0;
        }

        // Check for EOF
        next_char = getc(fp_in);
        if (next_char == EOF)
        {
            ungetc(next_char, fp_in);
            break;
        }
        else
            ungetc(next_char, fp_in);
    }

    fclose(fp_in);

    return 0;
}