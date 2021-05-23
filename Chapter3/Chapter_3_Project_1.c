#include <stdio.h>
int main()
{
    int day, month, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);

    printf("You entered the date %4.4d%2.2d%2.2d\n",year,month,day);
    return 0;
}