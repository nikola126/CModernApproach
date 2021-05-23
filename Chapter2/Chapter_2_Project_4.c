#include <stdio.h>
int main()
{
    float money = 0;

    printf("Enter an amount (ex: 1.50, 3.40 0.99) >> ");
    scanf("%f", &money);

    float tax_percent = 5.0;    // tax percentage
    float after_tax = money * ((100.0 + tax_percent)/100.0);
    printf("With tax added: $%.2f\n",after_tax);

    return 0;
}