#include <stdio.h>
#include <string.h>
#include <math.h>

// 1 if both (x) and (y) fall between 0 and (n-1)
#define CHECK(x, y, n) ((0 < (x) && (x) <= (n - 1)) && (0 < (y) && (y) <= (n - 1))) ? 1 : 0

// median of x, y, z
#define MEDIAN(x, y, z)                                                                 \
    (abs(x) > abs(y) && abs(x) < abs(z)) ? x : (abs(x) > abs(z) && abs(x) < abs(y)) ? x \
                                           : (abs(y) > abs(x) && abs(x) < abs(z))   ? y \
                                           : (abs(y) > abs(z) && abs(x) < abs(y))   ? y \
                                           : (abs(z) > abs(x) && abs(z) < abs(y))   ? z \
                                           : (abs(z) > abs(y) && abs(z) < abs(x))   ? z \
                                                                                    : 0

// calculates polynomial
#define POLYNOMIAL(x) 3.0 * pow((x), 5.0) + 2.0 * pow((x), 4.0) - 5.0 * pow((x), 3.0) - pow((x), 2.0) + 7.0 * x - 6.0

int main()
{
    printf("CHECK(%d, %d, %d): %d\n", 5, 12, 15, CHECK(5, 12, 15));
    printf("MEDIAN(%d,%d,%d): %d\n", 5, 3, 4, MEDIAN(5, 3, 4));
    printf("POLYNOMIAL(%g): %g\n", 3.0, POLYNOMIAL(3.0));
}