#include <stdio.h>
int main()
{
	int user_input, number;
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &user_input);

	number = user_input;
	int pos5,pos4,pos3,pos2,pos1;

	pos5 = number % 8;
	number /= 8;
	pos4 = number % 8;
	number /= 8;
	pos3 = number % 8;
	number /= 8;
	pos2 = number % 8;
	number /= 8;
	pos1 = number % 8;
	printf("Manual:  %d%d%d%d%d\n",pos1,pos2,pos3,pos4,pos5);

	// quick, padded with zeros, 5 digits max
	printf("Using %%o:%05o", user_input);

    return 0;
}