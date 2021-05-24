#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	// one month calendar
	int days, starting_day;

	printf("Enter number of days in month: ");
	scanf("%d", &days);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &starting_day);

	// print as many days as there are in a month
	for (int i = 1; i < days + starting_day; i++)
	{
		if (i < starting_day)
			printf("\t");
		else
			printf("%d\t", i - starting_day + 1);

		// new line after every 7 days
		if (i % 7 == 0 && i != 0)
			printf("\n");
	}
}