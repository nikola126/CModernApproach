#include <stdio.h>
int main()
{
    float x = 0;

    printf("Enter x: ");
    scanf("%f", &x);

    // Using Horner's Rule
    float expression = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("Polynomial: %f\n", expression);

    return 0;
}