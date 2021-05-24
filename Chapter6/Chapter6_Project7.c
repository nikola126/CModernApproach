#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	// initializes i, tests i and increments i
	// no multiplication
	int i, n, odd, square;

	printf("The program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	i = 1;
	odd = 3;
	square = 1;
	printf("--- --- ---\n");
	for (i = 1; i <= n; odd += 2, ++i)
	{
		printf("%10d%10d\n", i, square);
		square += odd;
	}
}