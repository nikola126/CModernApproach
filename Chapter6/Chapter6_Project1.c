#include <stdio.h>
#include <stdbool.h>

int main()
{
   	int number, max = 0;
    printf("Enter numbers. (Enter 0 to stop.)\n");
	do
	{
		printf(">> ");
		scanf("%d", &number);

		if (number >= max)
			max = number;

	} while (number > 0);

	printf("The largest number entered was %d", max); 
}