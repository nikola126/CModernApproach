#include <stdio.h>
#include <stdbool.h>

int main()
{
	int digit_1, digit_2, digit_3, digit_4;
	int max1, max2, min1, min2, max, min;
	printf("Enter 4 space separated digits: ");
	scanf("%d %d %d %d", &digit_1, &digit_2, &digit_3, &digit_4);

	if (digit_1 > digit_2)
	{
		max1 = digit_1;
		min1 = digit_2;
	}
	else
	{
		max1 = digit_2;
		min1 = digit_1;
	}
	if (digit_3 > digit_4)
	{
		max2 = digit_3;
		min2 = digit_4;
	}
	else
	{
		max2 = digit_4;
		min2 = digit_3;
	}

	if (max1 > max2)
		max = max1;
	else
		max = max2;

	if (min1 < min2)
		min = min1;
	else
		min = min2;

	printf("Largest digit: %d\n", max);
	printf("Smallest digit: %d\n", min);
}