#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50

int main()
{
    // open file for reading
    char filename[MAX_FILENAME_LEN];
    printf("Enter file to read: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file for reading.\n");
        exit(EXIT_FAILURE);
    }

    int number;
    float price;
    int day, month, year;

    // print data header
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    while (fscanf(fp, "%d,%f,%d/%d/%d\n", &number, &price, &month, &day, &year) == 5)
    {
        // print data
        printf("%d\t\t$%6.2f\t\t%2d/%2d/%4d\n", number, price, month, day, year);
    }
    fclose(fp);

    return 0;
}