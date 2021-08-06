#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void format1()
{
    time_t now = time(NULL);
    struct tm *timedata;
    char date_string[37];

    timedata = localtime(&now);
    strftime(date_string, sizeof(date_string), "%A %B %d %Y %I:%M", timedata);

    printf("Format 1:\t");
    puts(date_string);
}

void format2()
{
    time_t now = time(NULL);
    struct tm *timedata;
    char date_string[22];

    timedata = localtime(&now);
    strftime(date_string, sizeof(date_string), "%a, %d %b %y %H:%M", timedata);

    printf("Format 2:\t");
    puts(date_string);
}

void format3()
{
    time_t now = time(NULL);
    struct tm *timedata;
    char date_string[9];
    char time_string[12];

    timedata = localtime(&now);
    strftime(date_string, sizeof(date_string), "%m/%d/%y", timedata);
    strftime(time_string, sizeof(time_string), "%I:%M:%S %p", timedata);

    printf("Format 3:\t");
    printf("%s ",date_string);
    // conditional formatting for leading zeros in hours
    if (time_string[0] == '0')
        printf("%s\n", time_string[1]);
    else
        printf("%s\n", time_string);
}

int main()
{
    format1();
    format2();
    format3();
}