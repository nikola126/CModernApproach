#include <stdio.h>
#include <stdbool.h>

int main()
{
    int number, first_digit, second_digit;

    const char *first_digit_one[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                     "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    const char *first_digit_arr[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                                     "Seventy", "Eighty", "Ninety"};
    const char *last_digit_arr[] = {"", "-one", "-two", "-three", "-four", "-five",
                                    "-six", "-seven", "-eight", "-nine"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &first_digit, &second_digit);

    if (first_digit == 1)
    {
        printf("%s\n", first_digit_one[second_digit]);
    }
    else
    {
        printf("%s%s\n", first_digit_arr[first_digit - 2], last_digit_arr[second_digit]);
    }
}