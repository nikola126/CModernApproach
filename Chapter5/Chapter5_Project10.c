#include <stdio.h>
#include <stdbool.h>

int main()
{
	int grade, ten_digit = 0;
	printf("Enter numerical grade: ");
	scanf("%d", &grade);

	if (grade >= 100)
		ten_digit = 9;
	else
		ten_digit = grade / 10;

	switch (ten_digit)
	{
	case 9:
		printf("Letter Grade: A\n");
		break;
	case 8:
		printf("Letter Grade: B\n");
		break;
	case 7:
		printf("Letter Grade: C\n");
		break;
	case 6:
		printf("Letter Grade: D\n");
		break;
	default:
		printf("Letter Grade: F\n");
		break;
	}
}