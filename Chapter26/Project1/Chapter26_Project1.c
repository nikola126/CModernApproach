#include <stdio.h>
#include <stdlib.h>

int main()
{
    // set seed
    int seed = 123;
    int count = 100;
    srand(seed);

    printf("%d random integers. Only low bits.\n", count);
    for (int i = 1; i <= count; i++)
    {
        printf("%d ", (rand() & 1));
        if (i % 20 == 0)
            printf("\n");
    }
}