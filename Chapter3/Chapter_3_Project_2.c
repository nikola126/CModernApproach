#include <stdio.h>
int main()
{
    int number;
    float price;
    int day, month, year;

    printf("Enter item number: ");
    scanf("%d", &number);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");

    printf("%d\t\t$%6.2f\t\t%d/%d/%d\n", number, price, month, day, year);

    return 0;
}