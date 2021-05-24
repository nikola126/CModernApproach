#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	int number, num_squared, square;
	printf("Enter a positive number: ");
	scanf("%d", &number);

	// all even squares between 1 and n
	num_squared = sqrt(number);
	printf("All even numbers between 1 and %d: \n", number);
	for (int i = 1; i <= num_squared; i++)
	{
		square = i * i;
		if (square % 2 == 0)
			printf("%d\n", square);
	}
}