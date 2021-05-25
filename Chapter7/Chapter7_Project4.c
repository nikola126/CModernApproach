#include <stdio.h>
#include <ctype.h>

int main()
{
	char num_char;
	printf("Enter phone number: ");

	while ((num_char = getchar()) != '\n') 
	{
		num_char = toupper(num_char);
		switch (num_char) {
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
			putchar(num_char);
		}
	}
}