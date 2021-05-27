#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 10

// low, middle and high are pointers to array elements
int* split(int a[], int* low, int* high)
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


int main(void) 
{
	int a[N], i;

	printf("Enter %d numbers to be sorted:\n", N);
	for (int i = 0; i < N; i++)
	{
		printf(">> ");
		scanf("%d", &a[i]);
	}

	// a as entire array
	// a as pointer to 0th element
	// a as pointer offset to the last element
	quicksort(a, a, a + N - 1);

	printf("In sorted order: ");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}