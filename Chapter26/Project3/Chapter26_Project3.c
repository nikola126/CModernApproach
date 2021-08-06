#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int compare(const void *a, const void *b)
{
    const int *A = (const int *)a;
    const int *B = (const int *)b;
    return (*A > *B) - (*A < *B);
}

int main()
{
    // create arrays
    int arr1[SIZE * 1];
    int arr2[SIZE * 10];
    int arr3[SIZE * 100];

    // populate
    for (int i = 0; i < (SIZE * 1); i++)
        arr1[i] = (SIZE * 1) - i;

    for (int i = 0; i < (SIZE * 10); i++)
        arr2[i] = (SIZE * 1) - i;

    for (int i = 0; i < (SIZE * 100); i++)
        arr3[i] = (SIZE * 1) - i;

    // sort and time
    clock_t elapsed_time = clock();
    qsort(arr1, SIZE * 1, sizeof(int), compare);
    printf("Time to sort %d elements: %g\n", SIZE * 1, (clock() - elapsed_time) / (double)CLOCKS_PER_SEC);

    qsort(arr2, SIZE * 10, sizeof(int), compare);
    printf("Time to sort %d elements: %g\n", SIZE * 10, (clock() - elapsed_time) / (double)CLOCKS_PER_SEC);

    qsort(arr3, SIZE * 100, sizeof(int), compare);
    printf("Time to sort %d elements: %2.3g\n", SIZE * 100, (clock() - elapsed_time) / (double)CLOCKS_PER_SEC);
}