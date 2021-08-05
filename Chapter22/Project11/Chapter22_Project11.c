#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
    char months[12][10] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    int day, month, year;

    printf("Enter a date in the following format:\n");
    printf("D-MM-YYYY\tD/MM/YYYY\n");
    printf(">> ");

    // get line
    char line[MAX_LEN];
    fgets(line, sizeof(line), stdin);

    // 2 format possibilities
    if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
    {
        printf("%s %d, %d", months[month - 1], day, year);
    }
    else if (sscanf(line, "%d-%d-%d", &month, &day, &year) == 3)
    {
        printf("%s %d, %d", months[month - 1], day, year);
    }
    else
        printf("Incorrect format!\n");

    return 0;
}
