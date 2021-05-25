#include <stdio.h>

int main()
{
	double n, sum = 0;
	printf("This program sums a series of integers. \n");
	printf("Enter integers (0 to terminate):\n");
	printf(">> ");
	scanf("%lf", &n);
	while (n != 0)
	{
		sum += n;
		printf(">> ");
		scanf("%lf", &n);
	}
	printf("The sum is: %.2lf\n", sum);

    return 0;
}