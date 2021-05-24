#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	int first_year, new_year, first_month, new_month, first_day, new_day;
	int earliest_year = 0, earliest_month = 0, earliest_day = 0;
	bool earlier_found = false;

	printf("Enter 0/0/0 to stop.\n");
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%2d", &first_month, &first_day, &first_year);

	if (first_year == 0 && first_month == 0 && first_day == 0)
	{
		printf("0/0/0 is the earliest date.\n");
		return 0;
	}
	else
	{
		// first date is the earliest
		earliest_year = first_year;
		earliest_month = first_month;
		earliest_day = first_day;
	}

	do
	{
		printf("Enter a date (mm/dd/yyyy): ");
		scanf("%2d/%2d/%2d", &new_month, &new_day, &new_year);

		if (new_year == 0 && new_month == 0 && new_day == 0)
			break;

		earlier_found = false;
		// check if each new date is earlier

		if (new_year < earliest_year)
		{
			earliest_year = new_year;
			earliest_month = new_month;
			earliest_day = new_day;
			earlier_found = true;
		}

		if (new_month < earliest_month)
		{
			earliest_year = new_year;
			earliest_month = new_month;
			earliest_day = new_day;
			earlier_found = true;
		}

		if (new_day < first_day && earlier_found)
		{
			earliest_year = new_year;
			earliest_month = new_month;
			earliest_day = new_day;
		}

	} while (new_year != 0 && new_month != 0 && new_day != 0);

	printf("%d/%d/%d is the earliest date.\n",earliest_month,earliest_day,earliest_year);
}