#include <stdio.h>
#include <ctype.h>

int main()
{
char num_char;
	int value = 0;
	printf("Enter a word: ");

	while ((num_char = getchar()) != '\n')
	{
		num_char = toupper(num_char);
		switch (num_char) {
		case 'A':
		case 'E':
		case 'I':
		case 'L':
		case 'N':
		case 'O':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
			value += 1;
			break;
		case 'D':
		case 'G':
			value += 2;
			break;
		case 'B':
		case 'C':
		case 'M':
		case 'P':
			value += 3;
			break;
		case 'F':
		case 'H':
		case 'V':
		case 'W':
		case 'Y':
			value += 4;
			break;
		case 'K':
			value += 5;
			break;
		case 'J':
		case 'X':
			value += 8;
			break;
		case 'Q':
		case 'Z':
			value += 10;
			break;
		default:
			printf("Invalid word!\n");
			break;
		}
	}

	printf("Value: %d\n", value);
}