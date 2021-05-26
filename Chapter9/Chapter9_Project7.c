#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int power(int x, int n)
{
	// Base Case
	if (n == 0)
		return 1;

	// Recursive Calls
	int intermediate;
	if (n % 2 == 0)
	{
		intermediate = power(x, n / 2);
		return intermediate * intermediate; // Even
	}
	else
		return x * power(x, n - 1); // Odd
}

int main()
{
	int user_base = 0, user_power = 0, result = 0;

	printf("Enter base: ");
	scanf("%d", &user_base);
	printf("Enter power: ");
	scanf("%d", &user_power);

	result = power(user_base, user_power);
	printf("%d to the power of %d is: %d\n", user_base, user_power, result);
}