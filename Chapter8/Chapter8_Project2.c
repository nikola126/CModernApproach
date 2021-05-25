#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	bool digit_seen[10] = { false };
	int digit_header[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int digit_occurences[10] = { 0 };
	int digit; long n; 
	bool repetition_found = false;

	printf("Enter a number (up to 10 digits): ");
	scanf("%10d", &n);

	while (n > 0)
	{
		digit = n % 10;

		for (int i = 0; i < (sizeof(digit_header) / sizeof(digit_header[0])); i++)
		{
			if (digit == digit_header[i])
				digit_occurences[i] += 1;
		}
		n /= 10;
	}

	// print header
	printf("Digit:\t\t\t");
	for (int i = 0; i < (sizeof(digit_header) / sizeof(digit_header[0])); i++)
	{
		printf("%d ", digit_header[i]);
	}
	printf("\n");

	// print occurences
	printf("Occurences:\t\t");
	for (int i = 0; i < (sizeof(digit_occurences) / sizeof(digit_occurences[0])); i++)
	{
		printf("%d ", digit_occurences[i]);
	}
	printf("\n");
}