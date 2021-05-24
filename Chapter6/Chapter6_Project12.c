#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	float eta = 1, epsilon;
	int n;
	printf("Enter series length [n]: ");
	scanf("%d", &n);
	printf("Enter current term minimal value [epsilon]: ");
	scanf("%f", &epsilon);

	float denominator = 1, current_term;

	for (int i = 1; i <= n; i++)
	{
		denominator *= i;
		current_term = 1 / denominator;
		if (current_term < epsilon)
		{
			printf("Minimal value reached. Current term is %.5f\n", current_term);
			break;
		}
		eta += current_term;
	}
	printf("Eta = %.2f\n", eta);
}