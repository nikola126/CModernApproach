#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct date
{
    int year;
    int month;
    int day;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    // store two dates
    int input_year, input_month, input_day;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &input_month, &input_day, &input_year);
    struct date first_date = {input_year, input_month, input_day};

    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &input_month, &input_day, &input_year);
    struct date second_date = {input_year, input_month, input_day};

    int result = compare_dates(first_date, second_date);

    switch (result)
    {
    case 0:
        printf("Dates are the same!\n");
        break;
    case -1:
        printf("First date is earlier!\n");
        break;
    case 1:
        printf("Second date is earlier!\n");
        break;
    default:
        break;
    }

    return 0;
}

// returns -1 if first is earlier
// returns 0 if both are the same
// return 1 if second is earlier
int compare_dates(struct date d1, struct date d2)
{
    // check years
    if (d1.year < d2.year)
    {
        return -1;
    }
    else if (d2.year < d1.year)
    {
        return 1;
    }

    // check months
    if (d1.month < d2.month)
    {
        return -1;
    }
    else if (d2.month < d1.month)
    {
        return 1;
    }

    // check days
    if (d1.day < d2.day)
    {
        return -1;
    }
    else if (d2.day < d1.day)
    {
        return 1;
    }

    // if all checks are passed, dates are the same
    return 0;
}