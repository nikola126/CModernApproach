#include <stdio.h>

int main()
{
    short s_i = 0, s_n = 0, s_result = 0;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in the table: ");
	scanf("%hd", &s_n);

	for (s_i = 1; s_i <= s_n; s_i++)
	{
        s_result = s_i * s_i;
		if (s_result < 0)
		{
			printf("%20hd%20hd\n", s_i, s_i * s_i);
			printf("OVERFLOW at SHORT i = %hd\n\n",s_i);
			break;
		}
		//printf("%20hd%20hd\n", s_i, s_result);
	}

	int i_i = 0, i_n = 0, i_result = 0;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in the table: ");
	scanf("%d", &i_n);

	for (i_i = 1; i_i <= i_n; i_i++)
	{
        i_result = i_i * i_i;
		if (i_result < 0)
		{
			printf("%20d%20d\n", i_i, i_result);
			printf("OVERFLOW at INT i = %d\n\n", i_i);
			break;
		}
		//printf("%20d%20d\n", i_i, i_result);
	}

	long int l_i = 0, l_n = 0, l_result = 0;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in the table: ");
	scanf("%ld", &l_n);

	for (l_i = 1; l_i <= l_n; l_i++)
	{
        l_result = l_i * l_i;
		if (l_result < 0)
		{
			printf("%20ld%20ld\n", l_i, l_result);
			printf("OVERFLOW at LONG i = %ld\n\n", l_i);
			break;
		}
		//printf("%20ld%20ld\n", l_i, l_i * l_i);
	}

    return 0;
}