#include <stdio.h>
#include <complex.h>
#include <math.h>

#define PI (acos(-1.0))

int main()
{
    // cartesian form
    double real, imag, abs_val;

    printf("Enter a complex number in cartesian form (A + Bi):\n");
    printf("A >> ");
    scanf("%lf", &real);
    printf("B >> ");
    scanf("%lf", &imag);

    // polar form
    double r, theta;

    r = sqrt(real * real + imag * imag);
    theta = atan(imag / real);

    // adjust theta depending on point quadrant
    int quadrant;
    if (real > 0 && imag > 0)
        quadrant = 1;
    else if (real < 0 && imag > 0)
        quadrant = 2;
    else if (real < 0 && imag < 0)
        quadrant = 3;
    else
        quadrant = 4;

    if (quadrant == 2 || quadrant == 3)
        theta = theta + PI;
    if (quadrant == 4)
        theta = theta + (2 * PI);

    // print as radians
    printf("%.2lf + %.2lfi = %.2lf*(cos(%.2lf)+isin(%.2lf)) [rad]\n", real, imag, r, theta, theta);

    // print as degrees
    theta = theta * 180 / PI; // convert to degrees
    printf("%.2lf + %.2lfi = %.2lf*(cos(%.2lf)+isin(%.2lf)) [deg]\n", real, imag, r, theta, theta);
}