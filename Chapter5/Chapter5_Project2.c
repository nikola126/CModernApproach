#include <stdio.h>
#include <stdbool.h>

int main()
{
	int full_h, full_m, ampm_h;
	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &full_h, &full_m);

	if (full_h > 12)
	{
		// PM
		ampm_h = full_h - 12;
		printf("Equivalent 12-hour time: %2.2d:%2d PM", ampm_h, full_m);
	}
	else if (full_h < 12)
	{
		// AM
		printf("Equivalent 12-hour time: %2.2d:%2d AM", full_h, full_m);
	}
	else
	{
		// PM at 12
		printf("Equivalent 12-hour time: 12:%2d PM", full_m);
	}
}