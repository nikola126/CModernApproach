#include <stdio.h>
int main()
{
    int i, j, k;

    i = 5, j = 3;
    printf("%d %d \n", i / j, i % j);
    // 5 / 3 , 5 % 3
    // 1 2

    i = 2, j = 3;
    printf("%d\n", (i + 10) % j);
    // 12 % 3
    // 0

    i = 7, j = 8, k = 9;
    printf("%d\n", (i + 10) % k / j);
    // 17 % 9 / 8
    // 8 / 8
    // 1

    i = 1, j = 2, k = 3;
    printf("%d\n", (i + 5) % (j + 2) / k);
    // 6 % 4 / 3
    // 2 / 3
    // 0

    return 0;
}