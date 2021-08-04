#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    int words = 0, lines = 1, characters = 0;

    if (argc == 1)
    {
        printf("usage: filecounter filename\n");
        exit(EXIT_FAILURE);
    }

    // open file
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("%s can NOT be opened!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        characters += 1;

        if (ch == '\n')
            lines += 1;
        if (ch == ' ' || ch == '\t')
            words += 1;
    }

    fclose(fp);

    printf("In %s there are:\n", argv[1]);
    printf("%d lines, %d words, %d characters.\n", lines, words, characters);

    return 0;
}