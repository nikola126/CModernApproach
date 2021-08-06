#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // get date
    struct tm date;
    int next;

    printf("Enter day (1-31): ");
    scanf("%d", &date.tm_mday);

    printf("Enter month (1-12): ");
    scanf("%d", &date.tm_mon);

    printf("Enter year: ");
    scanf("%d", &date.tm_year);

    printf("Enter number of days in the future: ");
    scanf("%d", &next);

    // initialize time fields
    date.tm_sec = 0;
    date.tm_min = 0;
    date.tm_hour = 0;

    // remove offset
    date.tm_mon -= 1;
    date.tm_year -= 1900;
    date.tm_isdst = -1;

    // print future date
    date.tm_mday += next;
    mktime(&date);
    printf("Future date: %d/%d/%d\n", date.tm_mon + 1, date.tm_mday, date.tm_year + 1900);
}