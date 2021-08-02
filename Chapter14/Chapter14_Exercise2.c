#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NELEMS(a) sizeof(a) / sizeof(a[0])

int main()
{
    printf("Using macros:\n");
    int big_array[101] = {0};
    printf("Number of elements is: %d\n", NELEMS(big_array));
}