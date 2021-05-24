#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("Enter a number: ");
	int number;
	int digits = 0;
	scanf("%d", &number);

	if (0 < number && number <= 9)
	{
		printf("The number %d has %d digit.\n", number, 1);
	}
	else if(10 < number && number <= 99)
	{
		printf("The number %d has %d digits.\n", number, 2);
	}
	else if (100 < number && number <= 999)
	{
		printf("The number %d has %d digits.\n", number, 3);
	}
	else if (1000 < number && number <= 9999)
	{
		printf("The number %d has %d digits.\n", number, 4);
	}
	else
	{
		printf("The number %d has more than %d digits.\n", number, 4);
	}

}