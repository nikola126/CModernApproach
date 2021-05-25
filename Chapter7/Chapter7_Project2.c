#include <stdio.h>

int main()
{
	int i_i = 0, i_n = 0, i_result = 0;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in the table: ");
	scanf("%d", &i_n); getchar(); // skips the initial new line

	for (i_i = 1; i_i <= i_n; i_i++)
	{
        i_result = i_i * i_i;
		if (i_i % 24 == 0)
		{
			printf("Press Enter to Continue...");
			while (getchar() != '\n');
		}

		if (i_result < 0)
		{
			printf("%20d%20d\n", i_i, i_result);
			printf("OVERFLOW at INT i = %d\n\n", i_i);
			break;
		}
		printf("%20d%20d\n", i_i, i_result);
	}

    return 0;
}