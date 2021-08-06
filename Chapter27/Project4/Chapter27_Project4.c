#include <complex.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define PI (acos(-1.0))

int main()
{
    int n;
    printf("Enter n: >> ");
    scanf("%d", &n);
    printf("----- ----- ----- ----- -----\n");

    double complex root_of_unity;

    for (int k = 0; k < n; k++)
    {
        root_of_unity = cexp(2 * PI * I * (double)k / n);
        // better format
        if (cimag(root_of_unity) < 0)
            printf("%d\t%.3lf - %.3lfi\n", k, creal(root_of_unity), -cimag(root_of_unity));
        else
            printf("%d\t%.3lf + %.3lfi\n", k, creal(root_of_unity), cimag(root_of_unity));
    }
    printf("----- ----- ----- ----- -----\n");
}