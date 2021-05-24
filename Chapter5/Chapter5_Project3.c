#include <stdio.h>
#include <stdbool.h>

int main()
{
	float commission_main, commission_rival, value, shares, price;
	printf("Enter Shares and Price per share (space separated): ");
	scanf("%f %f", &shares, &price);

	value = shares * price;

	// original broker commission
	if (value < 2500.00f)
		commission_main = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission_main = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission_main = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission_main = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission_main = 155.00f + .0011f * value;
	else
		commission_main = 255.00f + .0009f * value;

	if (commission_main < 39.00f)
		commission_main = 39.00f;

	// rival broker commission
	if (shares < 2000)
	{
		commission_rival = 33.00f + .02f * shares;
	}
	else if (shares >= 2000)
	{
		commission_rival = 33.00f + .02f * shares;
	}

	printf("Original broker commission:\t$%.2f\n", commission_main);
	printf("Rival broker commission:\t$%.2f\n", commission_rival);
}