#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // get dates
    struct tm date1;
    struct tm date2;

    // date 1
    printf("DATE 1\n");
    printf("Enter day (1-31): ");
    scanf("%d", &date1.tm_mday);

    printf("Enter month (1-12): ");
    scanf("%d", &date1.tm_mon);

    printf("Enter year: ");
    scanf("%d", &date1.tm_year);

    // initialize time fields
    date1.tm_sec = 0;
    date1.tm_min = 0;
    date1.tm_hour = -1;

    // remove offset
    date1.tm_mon -= 1;
    date1.tm_year -= 1900;

    // date 2
    printf("DATE 2\n");
    printf("Enter day (1-31): ");
    scanf("%d", &date2.tm_mday);

    printf("Enter month (1-12): ");
    scanf("%d", &date2.tm_mon);

    printf("Enter year: ");
    scanf("%d", &date2.tm_year);

    // initialize time fields
    date2.tm_sec = 0;
    date2.tm_min = 0;
    date2.tm_hour = -1;

    // remove offset
    date2.tm_mon -= 1;
    date2.tm_year -= 1900;

    // compare
    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    int diff = (int)difftime(time1, time2) / 60 / 60 / 24;
    printf("Difference (in days) between the two dates: %d\n", diff);
}