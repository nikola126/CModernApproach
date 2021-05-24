#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	float eta = 1, factorial;
	int n;
	printf("Enter series length [n]: ");
	scanf("%d", &n);
	float denominator = 1;

	for (int i = 1; i <= n; i++)
	{
		denominator *= i;
		eta += 1 / denominator;
	}
	printf("Estimated [e] = %f\n", eta);
}