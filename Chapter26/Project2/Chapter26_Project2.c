#include <stdio.h>
#include <stdlib.h>

void thatsall()
{
    printf("That's all ");
}

void folks()
{
    printf("folks!\n");
}

int main()
{
    // called in reversed order!
    atexit(folks);
    atexit(thatsall);

    exit(0);
}