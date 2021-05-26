#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

double polynomial(double x)
{
	double result = 3 * pow(x,5) + 2 * pow(x,4) - 5 * pow(x,3) - pow(x,2) + 7 * x + 6;
	return result;
}

int main()
{
	double x = 0, result = 0;
	printf("Enter value for x: ");
	scanf("%lf", &x);

	result = polynomial(x);
	printf("Result: %.2lf\n",result);
}