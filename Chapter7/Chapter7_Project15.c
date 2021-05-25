#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	// ******************************************************************************
	short short_loop_n = 1;
	short short_factorial = 1;

	do
	{
		// calculate factorial
		for (short i = short_loop_n; i >= 1; i--)
			short_factorial *= i;

		// check for overflow
		if (short_factorial > 0)
		{
			// printf("Factorial of %d: %d\n", short_loop_n, short_factorial);
			// reset
			short_factorial = 1;
			short_loop_n++;
		}
		else
		{
			printf("Factorial of %d: %d\n", short_loop_n, short_factorial);
			printf("With SHORT variables, the largest accurate factorial is %d!\n\n", short_loop_n - 1);
			break;
		}
	} while (true);

	// ******************************************************************************
	int int_loop_n = 1;
	int int_factorial = 1;

	do
	{
		// calculate factorial
		for (int i = int_loop_n; i >= 1; i--)
			int_factorial *= i;

		// check for overflow
		if (int_factorial > 0)
		{
			// printf("Factorial of %d: %d\n", int_loop_n, int_factorial);
			// reset
			int_factorial = 1;
			int_loop_n++;
		}
		else
		{
			printf("Factorial of %d: %d\n", int_loop_n, int_factorial);
			printf("With INT variables, the largest accurate factorial is %d!\n\n", int_loop_n - 1);
			break;
		}
	} while (true);

	// ******************************************************************************
	long long_loop_n = 1;
	long long_factorial = 1;

	do
	{
		// calculate factorial
		for (long i = long_loop_n; i >= 1; i--)
			long_factorial *= i;

		// check for overflow
		if (long_factorial > 0)
		{
			// printf("Factorial of %ld: %ld\n", long_loop_n, long_factorial);
			// reset
			long_factorial = 1;
			long_loop_n++;
		}
		else
		{
			printf("Factorial of %ld: %ld\n", long_loop_n, long_factorial);
			printf("With LONG variables, the largest accurate factorial is %ld!\n\n", long_loop_n - 1);
			break;
		}
	} while (true);

	// ******************************************************************************
	long long long_long_loop_n = 1;
	long long long_long_factorial = 1;

	do
	{
		// calculate factorial
		for (long long i = long_long_loop_n; i >= 1; i--)
			long_long_factorial *= i;

		// check for overflow
		if (long_long_factorial > 0)
		{
			// printf("Factorial of %lld: %lld\n", long_long_loop_n, long_long_factorial);
			// reset
			long_long_factorial = 1;
			long_long_loop_n++;
		}
		else
		{
			printf("Factorial of %lld: %lld\n", long_long_loop_n, long_long_factorial);
			printf("With LONG LONG variables, the largest accurate factorial is %ld!\n\n", long_long_loop_n - 1);
			break;
		}
	} while (true);

	// ******************************************************************************
	float float_loop_n = 1;
	float float_factorial = 1;

	do
	{
		// calculate factorial
		for (float i = float_loop_n; i >= 1; i--)
			float_factorial *= i;

		// check for overflow
		if (float_factorial != INFINITY)
		{
			// printf("Factorial of %f: %f\n", float_loop_n, float_factorial);
			// reset
			float_factorial = 1;
			float_loop_n++;
		}
		else
		{
			printf("Factorial of %f: %f\n", float_loop_n, float_factorial);
			printf("With FLOAT variables, the largest accurate factorial is %.0f!\n\n", float_loop_n - 1);
			break;
		}
	} while (true);

	// ******************************************************************************
	double double_loop_n = 1;
	double double_factorial = 1;

	do
	{
		// calculate factorial
		for (double i = double_loop_n; i >= 1; i--)
			double_factorial *= i;

		// check for overflow
		if (double_factorial != INFINITY)
		{
			// printf("Factorial of %f: %f\n", double_loop_n, double_factorial);
			// reset
			double_factorial = 1;
			double_loop_n++;
		}
		else
		{
			printf("Factorial of %lf: %lf\n", double_loop_n, double_factorial);
			printf("With DOUBLE variables, the largest accurate factorial is %.0lf!\n\n", double_loop_n - 1);
			break;
		}
	} while (true);

	// ******************************************************************************
}