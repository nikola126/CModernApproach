#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    int orig_char, new_char;

    if (argc != 3)
    {
        printf("usage: xor.exe input.txt output.txt\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp_in = fopen(argv[1], "rb");
    FILE *fp_out = fopen(argv[2], "wb");

    if (fp_in == NULL)
        printf("%s could not be opened!\n", argv[1]);
    if (fp_out == NULL)
        printf("%s could not be opened!\n", argv[2]);

    while ((orig_char = getc(fp_in)) != EOF)
    {
        new_char = orig_char ^ KEY;
        putc(new_char, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}