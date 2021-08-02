#include <stdio.h>

#define M 10

int main()
{
#if M
    printf("(a) passed.\n");
#endif
#ifdef M
    printf("(b) passed\n");
#endif
#ifndef M
    printf("(c) passed\n");
#endif
#if defined(M)
    printf("(d) passed\n");
#endif
#if !defined(M)
    printf("(e) passed\n");
#endif
}