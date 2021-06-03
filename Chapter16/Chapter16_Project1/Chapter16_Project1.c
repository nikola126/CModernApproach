#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dialing_code
{
	const char* country;
	int code;
};

struct dialing_code country_codes[] =
{
	{"Argentina", 54},
	{"Brazil", 55},
	{"China", 86},
    {"Egypt",20},
    {"France",33},
    {"Germany",49},
};

int main(void)
{
	int user_code;
	int countries = sizeof(country_codes) / sizeof(country_codes[0]);
	printf("Enter an international dialing code: ");
	scanf("%d", &user_code);

	for (int i = 0; i < countries; i++)
	{
		if (country_codes[i].code == user_code)
		{
			printf("Country: %s\n", country_codes[i].country);
			return 0;
		}
	}
	printf("Country with this code was not found.\n");

	return 0;
}