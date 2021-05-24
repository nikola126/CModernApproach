#include <stdio.h>
#include <stdbool.h>

int main()
{
	int input_num, input_denom, remainder, gcd;
	printf("Enter a fraction [a/b] :");
	scanf("%d/%d", &input_num, &input_denom);

	int num = input_num; 
	int denom = input_denom;

	// find GCD
	if (num == 0)
	{
		gcd = denom;
		return 0;
	}
	while (num != 0)
	{
		remainder = denom % num;
		denom = num;
		num = remainder;
	}
	gcd = denom;
	printf("GCD: %d\n", gcd);

	// divide by GCD
	int new_num = input_num / gcd;
	int new_denom = input_denom / gcd;
	printf("In lowest terms: %d/%d\n", new_num, new_denom);
}