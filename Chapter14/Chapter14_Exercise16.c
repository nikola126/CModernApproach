#include <stdio.h>
#include <string.h>
#include <math.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main()
{
    IDENT(foo)

    return 0;
}