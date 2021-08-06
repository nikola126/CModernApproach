#include <stdio.h>
#include <complex.h>
#include <math.h>

#define PI (acos(-1.0))

int main()
{
    // cartesian form
    double real, imag;

    // polar form
    double r, theta;

    printf("Enter a complex number in polar form (R + THETA):\n");
    printf("R >> ");
    scanf("%lf", &r);
    printf("THETA >> ");
    scanf("%lf", &theta);

    int input_as_deg = 0;
    printf("Angle in degrees? [1/0] >> ");
    scanf("%d", &input_as_deg);

    if (input_as_deg)
    {
        theta = theta * PI / 180.0; // convert angle to rad
        real = r * cos(theta);
        imag = r * sin(theta);

        printf("Cartesian form: %.3lf + %.3lfi\n", real, imag);
    }
    else
    {
        real = r * cos(theta);
        imag = r * sin(theta);

        printf("Cartesian form: %.3lf + %.3lfi\n", real, imag);
    }
}