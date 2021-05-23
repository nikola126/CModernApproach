#include <stdio.h>
int main()
{
	int num_one, num_two, num_three;
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &num_one, &num_two, &num_three);

	printf("You entered %d.%d.%d", num_one, num_two, num_three);

    return 0;
}