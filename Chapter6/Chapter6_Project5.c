#include <stdio.h>
#include <stdbool.h>

int main()
{
	int input = 1;
	while (input != 0)
	{
		printf("Enter number: ");
		scanf("%d", &input);
		// reverse
		do
		{
			printf("%d", input % 10);
			input = input / 10;
		} while (input != 0);
		printf("\n");
	}
}