#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DOUBLE(x) 2 * x
#define FIXED(x) (2 * (x))

int main()
{
    printf("Using macros:\n");
    printf("DOUBLE(1+2): %d\n", DOUBLE(1 + 2));
    printf("4/DOUBLE(2): %d\n", 4 / DOUBLE(2));
    printf("Fixed:\n");
    printf("DOUBLE(1+2): %d\n", FIXED(1 + 2));
    printf("4/DOUBLE(2): %d\n", 4 / FIXED(2));
}