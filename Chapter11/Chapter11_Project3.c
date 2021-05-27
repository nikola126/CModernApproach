#include <stdio.h>
#include <stdbool.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int intermediate_num = numerator, intermediate_denom = denominator;
    int remainder, gcd;

    if (numerator == 0)
    {
        // return earlier, answer is 0
        *reduced_numerator = 0;
        *reduced_denominator = 1;
        return;
    }
    else
    {
        // find GCD
        while (intermediate_num != 0)
        {
            remainder = intermediate_denom % intermediate_num;
            intermediate_denom = intermediate_num;
            intermediate_num = remainder;
        }
        gcd = intermediate_denom;
        printf("GCD: %d\n", gcd);
        // divide by GCD
        *reduced_numerator = numerator / gcd;
        *reduced_denominator = denominator / gcd;
    }
}

int main()
{
    int input_num, input_denom, remainder, gcd;
    printf("Enter a fraction [a/b]: ");
    scanf("%d/%d", &input_num, &input_denom);

    int num = input_num;
    int denom = input_denom;
    int reduced_num, reduced_denom;

    reduce(num, denom, &reduced_num, &reduced_denom);

    printf("In lowest terms: %d/%d\n", reduced_num, reduced_denom);
}