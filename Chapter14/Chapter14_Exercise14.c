#include <stdio.h>
#include <string.h>
#include <math.h>

#define N = 10  // cant initialize with this ERROR!
#define newN 10
#define INC(x) x + 1
#define SUB(x, y) x - y
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x, y) x##y
#define M2(x, y) #x #y

int main()
{
    int a[newN], i, j, k, m;

#ifdef N
    i = j;
#else
    j = i;
#endif

    i = 10 * INC(j);
    i = SUB(j, k);
    i = SQR(SQR(j));
    i = CUBE(j);
    // i = M1(j, k); // i = jk ERROR!
    puts(M2(i, j)); // ij works here, no error

#undef SQR
    // i = SQR(j); // using undefined function/macro ERROR
#define SQR
    i = SQR(j);

    return 0;
}