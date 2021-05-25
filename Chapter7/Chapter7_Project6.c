#include <stdio.h>
#include <ctype.h>

int main()
{
	unsigned long int size_var;

	printf("Size of int: %zu\n", size_var = sizeof(int));
	printf("Size of short: %zu\n", size_var = sizeof(short));
	printf("Size of long: %zu\n", size_var = sizeof(long));
	printf("Size of float: %zu\n", size_var = sizeof(float));
	printf("Size of double: %zu\n", size_var = sizeof(double));
	printf("Size of long double: %zu\n", size_var = sizeof(long double));
}