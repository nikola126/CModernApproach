#include <stdio.h>
#include <ctype.h>

int main()
{
	int user_input_h, user_input_m;
	int output_h;
	char time_specifier;

	printf("Enter a 12-hour time (HH:MM AM/PM): ");
	scanf("%d:%d %c", &user_input_h, &user_input_m, &time_specifier);

	//printf("HOUR : %d\tTIME: %d\nTIME SPECIFIER: %c\n", user_input_h, user_input_m, time_specifier);

	// if AM/PM not provided, use normal 24h format
	if (time_specifier == 'P' || time_specifier == 'p')
	{
		output_h = user_input_h + 12;
	}
	else if (time_specifier == 'A' || time_specifier == 'a')
	{
		output_h = user_input_h;
	}
	else
	{
		printf("Incorrect format.\n");
		return 0;
	}
	
	printf("Equivalent 24-hour time: %d:%d", output_h, user_input_m);
}