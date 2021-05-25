#include <stdio.h>
#include <ctype.h>

int main()
{
	int num1, denom1, num2, denom2, result_num, result_denom;
	char operation;

	printf("Enter two fractions, separated by operation sign:\n");
	printf("Example: [5/6 + 3/4] [1/2 / 7/8] etc.\n");
	printf(">> ");

	scanf("%d/%d %c %d/%d", &num1, &denom1, &operation, &num2, &denom2);

	switch (operation)
	{
	case '+':
		result_num = num1 * denom2 + num2 * denom1;
		result_denom = denom1 * denom2;
		printf("The sum is %d/%d\n", result_num, result_denom);
		break;
	case '-':
		result_num = num1 * denom2 - num2 * denom1;
		result_denom = denom1 * denom2;
		printf("The difference is %d/%d\n", result_num, result_denom);
		break;
	case '*':
		result_num = num1 * num2;
		result_denom = denom1 * denom2;
		printf("The product is %d/%d\n", result_num, result_denom);
		break;
	case '/':
		result_num = num1 * num2;
		result_denom = denom1 * denom2;
		printf("The quotient is %d/%d\n", result_num, result_denom);
		break;
	default:
		printf("Incorrect input.\n");
		break;
	}
}