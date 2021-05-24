#include <stdio.h>
#include <stdbool.h>

int main()
{
	int wind_force;
	printf("Enter wind force (in knots): ");
	scanf("%d", &wind_force);

	if (wind_force < 1)
	{
		printf("Calm\n");
	}
	else if (1 <= wind_force && wind_force <= 3)
	{
		printf("Light air\n");
	}
	else if (4 <= wind_force && wind_force <= 27)
	{
		printf("Breeze\n");
	}
	else if (28 <= wind_force && wind_force <= 47)
	{
		printf("Gale\n");
	}
	else if (48 <= wind_force && wind_force <= 63)
	{
		printf("Storm\n");
	}
	else if (wind_force > 63)
	{
		printf("Hurricane\n");
	}
}