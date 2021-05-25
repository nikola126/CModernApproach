#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const int arr_size_x = 5;
	const int arr_size_y = 5;
	int arr[arr_size_x][arr_size_y] = { 0 };
	int input = 1;

	for (int i = 0; i < arr_size_x; i++)
	{
		printf("Enter row %d (%d elements):\n", i + 1, arr_size_y);
		for (int j = 0; j < arr_size_y; j++)
		{
			printf(">> ");
			scanf("%d", &arr[i][j]);
		}

	}

	printf("Array:\n");
	for (int i = 0; i < arr_size_x; i++)
	{
		for (int j = 0; j < arr_size_y; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}

	printf("Row totals:\n");
	int sum = 0;
	for (int i = 0; i < arr_size_y; i++)
	{
		for (int j = 0; j < arr_size_y; j++)
			sum += arr[i][j];
		printf("%d ", sum);
		sum = 0;
	}
	printf("\n");

	printf("Column totals:\n");
	sum = 0;
	for (int j = 0; j < arr_size_y; j++)
	{
		for (int i = 0; i < arr_size_y; i++)
			sum += arr[i][j];
		printf("%d ", sum);
		sum = 0;
	}
	printf("\n");
}