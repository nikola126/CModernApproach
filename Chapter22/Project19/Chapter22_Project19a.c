#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: files.exe testing.txt output.txt\n");
        exit(EXIT_FAILURE);
    }

    // try to open files
    FILE *fp_in;
    FILE *fp_out;

    if ((fp_in = fopen(argv[1], "rb")) == NULL)
    {
        printf("File %s could not be opened!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp_out = fopen(argv[2], "wb")) == NULL)
    {
        printf("File %s could not be opened!\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Windows to UNIX
    char ch;
    while (true)
    {
        ch = fgetc(fp_in);
        if (ch == EOF)
            break;

        // replace carriage-return (end-of-line)
        if (ch == '\x0d')
            fputc('\x0a', fp_out);
        // skip line-feed
        else if (ch == '\x0a')
            ;
        // skip end-of-file (may not be present)
        else if (ch == '\x1a')
            break;
        else
            fputc(ch, fp_out);
    }

    printf("Windows to UNIX Text File Conversion complete.\n");
    fclose(fp_in);
    fclose(fp_out);
}