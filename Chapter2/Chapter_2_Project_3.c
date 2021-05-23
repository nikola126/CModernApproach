#include <stdio.h>
int main()
{
    float PI = 3.1415;
    float radius = 10;

    printf("Enter radius of a sphere: ");
    scanf("%f", &radius);

    float volume = (4.0f / 3.0f) * PI * radius * radius * radius;
    printf("Volume of a sphere: %f", volume);

    return 0;
}