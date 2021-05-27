#include <stdio.h>

void pay_amount(int amount, int *bills_twenty, int *bills_ten, int *bills_five, int *bills_one)
{
    while (amount >= 20)
    {
        amount -= 20;
        *bills_twenty += 1;
    }
    while (amount >= 10)
    {
        amount -= 10;
        *bills_ten += 1;
    }
    while (amount >= 5)
    {
        amount -= 5;
        *bills_five += 1;
    }
    while (amount >= 1)
    {
        amount -= 1;
        *bills_one += 1;
    }
}

int main()
{
    int amount = 0;

    printf("Enter x: ");
    scanf("%d", &amount);

    int bills_twenty = 0, bills_ten = 0, bills_five = 0, bills_one = 0;

    pay_amount(amount, &bills_twenty, &bills_ten, &bills_five, &bills_one);

    printf("$20 bills : %d\n", bills_twenty);
    printf("$10 bills : %d\n", bills_ten);
    printf("$5 bills : %d\n", bills_five);
    printf("$1 bills : %d\n", bills_one);
    return 0;
}