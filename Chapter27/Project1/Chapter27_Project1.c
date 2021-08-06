#include <complex.h>
#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;

    printf("a*x^2 + b*x + c\n");
    printf("----- ----- -----\n");
    printf("Enter a: >> ");
    scanf("%lf", &a);
    printf("Enter b: >> ");
    scanf("%lf", &b);
    printf("Enter c: >> ");
    scanf("%lf", &c);
    printf("----- ----- -----\n");

    double discriminant = (b * b - 4 * a * c);
    printf("Discriminant: %.2lf\n", discriminant);

    if (discriminant < 0)
    {
        // complex roots
        double complex discriminant_sqrt = csqrt(b * b - 4 * a * c);
        double complex root1 = (-b + discriminant_sqrt) / (2 * a);
        double complex root2 = (-b - discriminant_sqrt) / (2 * a);
        // nicer output
        if (cimag(root1) < 0)
        {
            printf("root1 = %g - %gi\n", creal(root1), -cimag(root1));
        }
        else
            printf("root2 = %g + %gi\n", creal(root1), cimag(root1));
        if (cimag(root2) < 0)
        {
            printf("root1 = %g - %gi\n", creal(root2), -cimag(root2));
        }
        else
            printf("root2 = %g + %gi\n", creal(root2), cimag(root2));
    }
    else
    {
        // real roots
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %g\n", root1);
        printf("root2 = %g\n", root2);
    }
}