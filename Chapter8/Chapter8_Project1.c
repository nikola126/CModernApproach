#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	bool digit_seen[10] = { false };
	int digit; long n; bool repetition_found = false;

	printf("Enter a number (up to 10 digits): ");
	scanf("%d", &n);

	while (n > 0) 
	{
		digit = n % 10;
		//printf("n: %d\tdigit: %d\n", n, digit);
		if (digit_seen[digit])
		{
			printf("%d seen repeated.\n", digit);
			repetition_found = true;
		}

		digit_seen[digit] = true;
		n /= 10;
	}

	if (!repetition_found)

	{
		printf("No repeated digits\n");
    }
}