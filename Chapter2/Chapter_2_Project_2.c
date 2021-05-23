#include <stdio.h>
int main()
{
    float PI = 3.1415;
    int radius = 10;
    float volume = (4.0 / 3.0) * PI * radius * radius * radius;

    printf("Radius: %d\n", radius);
    printf("Volume of a sphere: %f", volume);

    return 0;
}