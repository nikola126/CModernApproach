#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CUBED(x) ((x) * (x))
#define REM4(x) ((x) % 4)
#define PROD(x, y) ((x) * (y) < 100 ? 1 : 0)

int main()
{
    printf("Using macros:\n");
    printf("Cube of %d: %d\n", 15, CUBED(15));
    printf("Remainder when %d is divided by 4: %d\n", 10, REM4(10));
    printf("Product of %d and %d less than 100? : %d\n", 15, 6, PROD(15, 6));
}