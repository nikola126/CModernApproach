#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char c;
    char binary[10];
    int bytes_read;
    int offset = 0;
    char to_print;

    if (argc != 2)
    {
        printf("usage: fcontent filename.txt\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "rb");

    if (fp == NULL)
    {
        printf("%s can't be opened!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset\t\t\tBytes\t\t\t\tCharacters\n");
    printf("------\t\t\t-----\t\t\t\t----------\n");

    // while there are bytes to read (at least 10)
    while ((bytes_read = fread(binary, sizeof(char), 10, fp)) > 0)
    {
        // print offset
        printf("%d\t\t", offset);
        offset += 10;

        // print as bytes
        for (int i = 0; i < 10; i++)
        {
            if (i >= bytes_read)
                printf("  "); // when there are less than 10 bytes
            else
                printf("%x ", binary[i]);
        }
        printf("\t\t");

        // print as characters
        for (int i = 0; i < bytes_read; i++)
        {
            to_print = binary[i];
            if (isprint(to_print))
                printf("%c", binary[i]);
            else
                printf(".");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}