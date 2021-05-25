#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	double x, old_y = 1, new_y = 1;
	printf("Enter a number: ");
	scanf("%lf", &x);

	// first step
	double difference = 0;
	double guess = (old_y + x / old_y) / 2;
	new_y = guess;

	int i = 0;
	// table header
	printf("\t\t\t\t\t\tAverage of\t\t\n");
	printf("x\t\ty\t\tx/y\t\ty and x/y\tDifference\n");
	while (true)
	{
		old_y = guess;
		guess = (old_y + x / old_y) / 2;
		new_y = guess;
		difference = fabs((new_y - old_y));

		printf("%.1lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\t\t%.5lf\n", 
		x, old_y, (x / old_y), guess, difference);
		i++;
		
		if (difference < (new_y * 0.00001f))
			break;
	}
	printf("Square root: %.5f\n", new_y);
}