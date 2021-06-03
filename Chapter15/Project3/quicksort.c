#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// low, middle and high are pointers to array elements
int *split(int a[], int *low, int *high)
{
    int part_element = *low;

    for (;;)
    {
        while (low < high && part_element <= *high)
            high--;
        if (low >= high)
            break;
        *low++ = *high;

        while (low < high && *low <= part_element)
            low++;
        if (low >= high)
            break;
        *high-- = *low;
    }

    *high = part_element;
    return high;
}

void quicksort(int a[], int *low, int *high)
{
    // receives (pointer to) array and also pointers to its first and last elements
    int *middle;

    if (low >= high)
        return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}