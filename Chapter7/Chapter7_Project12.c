#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
	float result = 0.0;
	float input_num = 0.0;

	char action;
	
	printf("Enter an expression (no parentheses, evaluated left to right)\n");
	printf(">> ");
	scanf("%f", &result);

	while ((action = getchar()) != '\n')
	{
		switch (action)
		{
		case '+':
			scanf("%f", &input_num);
			result += input_num;
			break;
		case '*':
			scanf("%f", &input_num);
			result *= input_num;
			break;
		case '-':
			scanf("%f", &input_num);
			result -= input_num;
			break;
		case '/':
			scanf("%f", &input_num);
			if (input_num == 0)
			{
				printf("Division by 0!\n");
				return 0;
			}
			result /= input_num;
			break;
		default:
			break;
		}
	}

	printf("Result: %.2f\n", result);
}