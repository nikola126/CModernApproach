#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    float amount, rate;
    int years;

    // get data
    printf("Enter amount deposited: ");
    scanf("%f", &amount);

    printf("Enter interest rate [%%]: ");
    scanf("%f", &rate);

    printf("Enter years: ");
    scanf("%d", &years);

    // calculate interest
    // P * e^(r*t)
    float interest;
    interest = amount * exp((rate / 100) * (float)years);

    printf("Interest after %d years: %.2f\n", years, interest);
}