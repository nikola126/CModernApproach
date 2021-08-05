#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, c;

    printf("ax^2 + bx + c\n");
    printf("Enter value for a: ");
    scanf("%lf", &a);
    printf("Enter value for b: ");
    scanf("%lf", &b);
    printf("Enter value for c: ");
    scanf("%lf", &c);

    printf("a = %.2f b = %.2f c = %.2f\n", a, b, c);

    // check for complex roots
    double d = pow(b, 2) - (4.0 * a * c);

    if (d < 0)
    {
        printf("d = %.2f < 0\t", d);
        printf("Complex roots!\n");
        return 0;
    }
    else
    {
        double x1 = -b + sqrt(d) / (2 * a);
        double x2 = -b - sqrt(d) / (2 * a);
        printf("Solutions are:\nx1 = %.2lf\tx2 = %.2lf\n", x1, x2);
    }
}