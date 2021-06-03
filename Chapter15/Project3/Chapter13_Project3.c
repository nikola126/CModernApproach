#include "quicksort.c"

#define N 10

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