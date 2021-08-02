#include <stdio.h>
#include <string.h>
#include <math.h>

#define DISP(f, x) printf("%s(%g) = %g\n", #f, x, f(x));
#define DISP2(f, x, y) printf("%s(%g,%g) = %g\n", #f, x, y, pow(x, y))

int main()
{
    DISP(sqrt, 3.0);
    DISP2(pow, 2.0, 10.0);
}