#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define TASK_4_SIZE (sizeof(a) / sizeof(a[0]))

int main()
{
	int a[N], i;

	printf("Enter %d numbers: \n", N);
	for (int i = 0; i < TASK_4_SIZE; i++)
	{
		printf(">> ");
		scanf("%d", &a[i]);
	}

	printf("In reverse order: ");
	for (int i = TASK_4_SIZE -1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}