#include <stdio.h>
int main()
{
    float x = 0;

    printf("Enter x: ");
    scanf("%f", &x);

    float expression = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    printf("Polynomial: %f\n", expression);

    return 0;
}