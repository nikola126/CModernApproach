#include <stdio.h>
#include <stdbool.h>

int main()
{
	int first_year, second_year, first_month, second_month, first_day, second_day;
	printf("Enter first date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &first_month, &first_day, &first_year);
	printf("Enter second date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &second_month, &second_day, &second_year);

	bool first_earlier = false, second_earlier = false;

	// Which date comes earlier? Compare years
	while (true)
	{
		if (first_year > second_year)
		{
			second_earlier = true;
			break;
		}
		else if (second_year > first_year)
		{
			first_earlier = true;
			break;
		}
		break;
	}

	if (first_earlier)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d.\n", first_month, first_day, first_year, second_month, second_day, second_year);
		return 0;
	}

	else if (second_earlier)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d.\n", second_month, second_day, second_year, first_month, first_day, first_year);
		return 0;
	}

	// Which date comes earlier? Compare months
	while (true)
	{
		if (first_month > second_month)
		{
			second_earlier = true;
			break;
		}
		else if (second_month > first_month)
		{
			first_earlier = true;
			break;
		}
		break;
	}

	if (first_earlier)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d.\n", first_month, first_day, first_year, second_month, second_day, second_year);
		return 0;
	}

	else if (second_earlier)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d.\n", second_month, second_day, second_year, first_month, first_day, first_year);
		return 0;
	}

	// Which date comes earlier? Compare days
	while (true)
	{
		if (first_day > second_day)
		{
			second_earlier = true;
			break;
		}
		else
		{
			first_earlier = true;
			break;
		}
		break;
	}

	if (first_earlier)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d.\n", first_month, first_day, first_year, second_month, second_day, second_year);
		return 0;
	}

	else if (second_earlier)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d.\n", second_month, second_day, second_year, first_month, first_day, first_year);
		return 0;
	}

	printf("The two dates are the same!\n");
}