#include <stdio.h>

#define N 5

void max_min(int a[], int n, int* max, int* min)
{
	// uses a pointer instead of integer
	int* i = NULL;

	*max = a[0];
	*min = a[0];

	for (i = a + 1; i < a + n; i++)
	{
		if (*i > *max)
			*max = *i;
		else if (*i < *min)
			*min = *i;
	}
}

int main(void)
{
	int b[N], i, big, small;

	printf("Enter %d numbers:\n", N);
	for (i = 0; i < N; i++)
	{
		printf(">> ");
		scanf("%d", &b[i]);
	}

	max_min(b, N, &big, &small);

	printf("\n");
	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);
}