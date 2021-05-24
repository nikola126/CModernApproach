#include <stdio.h>
int main()
{
	int first, middle, last;
	printf("Enter a three-digit number: ");

	scanf("%1d%1d%1d", &first, &middle, &last);

	printf("Reversed: %d%d%d\n", last, middle, first);

    return 0;
}