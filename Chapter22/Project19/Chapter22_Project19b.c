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

    // UNIX to Windows
    char ch;
    while (true)
    {
        ch = fgetc(fp_in);
        if (ch == EOF)
        {
            // add EOF marker (not necessary)
            fputc('\x1a', fp_out);
            break;
        }

        // add carriage-return (end-of-line) after line-feed
        if (ch == '\x0a')
        {
            fputc('\x0d', fp_out);
            fputc('\x0a', fp_out);
        }
        else
            fputc(ch, fp_out);
    }

    printf("UNIX to Windows Text File Conversion complete.\n");
    fclose(fp_in);
    fclose(fp_out);
}