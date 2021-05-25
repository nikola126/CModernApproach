#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	const int phone_length = 15; // 15 +1 for terminating character
	char phone_number[phone_length];
	char output;

	printf("Enter phone number (15-characters MAX): ");
	scanf("%s", &phone_number);
	printf("In numeric form: ");
	for (int i = 0; i < phone_length; i++)
	{
		output = toupper(phone_number[i]);
		// convert to numbers
		if (isalpha(output))
		{
			switch (output)
			{
			case 'A':
			case 'B':
			case 'C':
				printf("2");
				break;
			case 'D':
			case 'E':
			case 'F':
				printf("3");
				break;
			case 'G':
			case 'H':
			case 'I':
				printf("4");
				break;
			case 'J':
			case 'K':
			case 'L':
				printf("5");
				break;
			case 'M':
			case 'N':
			case 'O':
				printf("6");
				break;
			case 'P':
			case 'R':
			case 'S':
				printf("7");
				break;
			case 'T':
			case 'U':
			case 'V':
				printf("8");
				break;
			case 'W':
			case 'X':
			case 'Y':
				printf("9");
				break;
			default:
				putchar(output);
			}
		}
		else
			printf("%c", phone_number[i]);
	}
	printf("\n");
}