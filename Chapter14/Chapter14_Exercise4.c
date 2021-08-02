#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define AVG(x, y) (x + y) / 2
#define AREA(x, y) (x) * (y)

int main()
{
    printf("Using macros:\n");
    printf("AVG(1/3 , 2): %f\n", AVG(1.0 / 3.0, 2.0));
    printf("AREA(3 , 4/5): %f\n", AREA(3.0, 4.0 / 5.0));
}