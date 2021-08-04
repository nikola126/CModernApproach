#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if (argc == 1)
    {
        printf("usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }

    // open all files
    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("%s can NOT be opened!\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF)
            putchar(ch);    // concatenate in stdout

        fclose(fp);
    }

    return 0;
}