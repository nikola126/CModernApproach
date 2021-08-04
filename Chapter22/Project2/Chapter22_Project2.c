#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1)
    {
        printf("usage: capitalize filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("%s can NOT be opened!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("%s can be opened.\n", argv[1]);

    // capitalize letters (output to stdout)
    char ch;
    while ((ch = getc(fp))!= EOF)
    {
        putchar(toupper(ch));
    }
    

    return 0;
}