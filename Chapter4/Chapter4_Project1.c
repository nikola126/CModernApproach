#include <stdio.h>
int main()
{
    int first, last, user_input;
    printf("Enter a two-digit number: ");

    scanf("%2d", &user_input);
    first = user_input / 10;
    last = user_input % 10;
    printf("The reversal is: %d%d\n", last, first);
    return 0;
}