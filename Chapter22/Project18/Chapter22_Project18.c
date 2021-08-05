#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

#define MAX_ELEM 10000

int compare(const void *a, const void *b);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2)
    {
        printf("usage: integers testing.txt\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("%s could not be opened!\n");
        exit(EXIT_FAILURE);
    }

    int ints_array[MAX_ELEM];
    int ints_found = 0;

    // read up to 10k integers
    while (!feof(fp) && ints_found < MAX_ELEM)
    {
        // add to array
        fscanf(fp, " %d", &ints_array[ints_found]);
        ints_found += 1;
    }
    // ints_found -= 1;
    printf("There were %d numbers in the file.\n", ints_found);
    fclose(fp);

    // sort integers
    qsort(ints_array, ints_found, sizeof(int), compare);

    // calculate median
    int median;
    if (ints_found % 2 == 0)
    {
        median = (ints_array[(ints_found - 1) / 2] + ints_array[(ints_found - 1) / 2 + 1]) / 2;
    }
    else
    {
        median = ints_array[(ints_found - 1) / 2];
    }

    // show results
    printf("MAX: %d\tMIN: %d\nMEDIAN: %d\n", ints_array[ints_found - 1], ints_array[0], median);
}

// treats arguments as ints
// returns based on difference
int compare(const void *a, const void *b)
{
    const int *A = (const int *)a;
    const int *B = (const int *)b;
    return (*A > *B) - (*A < *B);
}