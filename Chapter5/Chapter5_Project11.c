#include <stdio.h>
#include <stdbool.h>

int main()
{
int number, first_digit, second_digit;
	printf("Enter a two-digit number: ");
	scanf("%1d%1d", &first_digit, &second_digit);

	switch (first_digit)
	{
	case 1:
		switch (second_digit)
		{
		case 0:
			printf("Ten\n");
			break;
		case 1:
			printf("Eleven\n");
			break;
		case 2:
			printf("Twelve\n");
			break;
		case 3:
			printf("Thirteen\n");
			break;
		case 4:
			printf("Fourteen\n");
			break;
		case 5:
			printf("Fifteen\n");
			break;
		case 6:
			printf("Sixteen\n");
			break;
		case 7:
			printf("Seventeen\n");
			break;
		case 8:
			printf("Eighteen\n");
			break;
		case 9:
			printf("Nineteen\n");
			break;
		default:
			break;
		}
		break;
	case 2:
		printf("twenty");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 3:
		printf("thirty");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 4:
		printf("forty");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 5:
		printf("fifty");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 6:
		printf("sixty");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 7:
		printf("seventy");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 8:
		printf("eighty");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	case 9:
		printf("ninety");
		switch (second_digit)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("-one\n");
			break;
		case 2:
			printf("-two\n");
			break;
		case 3:
			printf("-three\n");
			break;
		case 4:
			printf("-four\n");
			break;
		case 5:
			printf("-five\n");
			break;
		case 6:
			printf("-six\n");
			break;
		case 7:
			printf("-seven\n");
			break;
		case 8:
			printf("-eight\n");
			break;
		case 9:
			printf("-nine\n");
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}