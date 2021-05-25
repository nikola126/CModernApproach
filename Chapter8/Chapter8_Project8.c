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
		printf("Enter grades of student %d (%d quizzes):\n", i + 1, arr_size_y);
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

	// average score for each student
	int sum = 0;
	float average = 0;
	for (int i = 0; i < arr_size_y; i++)
	{
		for (int j = 0; j < arr_size_y; j++)
			sum += arr[i][j];
		printf("Student %d total score: %d ", i + 1, sum);
		printf("average score: %.2f\n", (float)sum/arr_size_y);
		sum = 0;
	}
	printf("\n");

	// for each quiz
	// average, high, low score
	sum = 0;
	int max = 0, min = 0;
	for (int j = 0; j < arr_size_y; j++)
	{
		max = arr[0][j]; min = arr[0][j];
		for (int i = 0; i < arr_size_y; i++)
		{
			sum += arr[i][j];
			if (arr[i][j] >= max)
				max = arr[i][j];
			if (arr[i][j] <= min)
				min = arr[i][j];
		}
		printf("Quiz %d average score: %.2f ", j + 1, (float)(sum)/arr_size_y);
		printf("highest score: %d lowest score: %d\n", max, min);
		sum = 0;
	}
	printf("\n");
}