#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100

void f(void);

int main()
{
    f();
#ifdef N
#undef N // N is undefined, function is compiled later
#endif
    return 0;
}

void f(void)
{
#if defined(N)
    printf("N is %d\n", N);
#else // at the time of compilation, N is undefined, this will print
    printf("N is undefined\n");
#endif
}