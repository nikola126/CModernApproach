#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main()
{
	int i, low_rate, num_years, year;
	double value[5];
	double monthly_rate;

	printf("Enter interest rate: ");
	scanf("%d", &low_rate);
	monthly_rate = (double) low_rate / 12;
	printf("Monthly rate: %.2f\n", monthly_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_years);

	// Years Header
	printf("\nYears");
	for (i = 0; i < NUM_RATES; i++)
	{
		printf("%8d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	// Monthly Interest
	for (year = 1; year <= num_years; year ++)
	{
		printf("%3d     ", year);
		for (i = 0; i < NUM_RATES; i++)
		{
			// calculate monthly interest for a year
			for (int j = 0; j < 12; j++)
			{
				value[i] += ((double)i + (double)monthly_rate) / 100.0 * value[i];
			}
			printf("%8.2f ", value[i]);
		}
		printf("\n");
	}
}