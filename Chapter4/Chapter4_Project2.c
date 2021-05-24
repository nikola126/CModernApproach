#include <stdio.h>
int main()
{
    int first, middle, last, user_input;
    printf("Enter a three-digit number: ");

    scanf("%3d", &user_input);
    first = (user_input / 100);
    middle = (user_input / 10) % 10;
    last = (user_input % 100) % 10;

    printf("Reversed: %d%d%d\n", last, middle, first);

    return 0;
}