#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main()
{
	const char *months_strings[] = {"January", "February", "March", "April", "May", "June",
									"July", "August", "September", "October", "November", "December"};

	int day, month, year;
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &month, &day, &year);

	printf("You entered the date %s %d, %d\n", months_strings[month - 1], day, year);
}