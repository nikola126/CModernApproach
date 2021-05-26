#include <stdio.h>

float income_tax(float income)
{
	float flat_tax, flex_tax, tax_due;

	if (income < 750.0f)
	{
		flat_tax = 0;
		flex_tax = 0.01 * income;
	}
	else if (750.00f <= income && income < 2250.00f)
	{
		flat_tax = 7.50;
		flex_tax = 0.02 * (income - 750.00f);
	}
	else if (2250.00f <= income && income < 3750.00f)
	{
		flat_tax = 37.50;
		flex_tax = 0.03 * (income - 2250.00f);
	}
	else if (3750.00f <= income && income < 5250.00f)
	{
		flat_tax = 82.50;
		flex_tax = 0.04 * (income - 3750.0f);
	}
	else if (5250.00f <= income && income <= 7000.00f)
	{
		flat_tax = 142.50;
		flex_tax = 0.05 * (income - 5250.0f);
	}
	else if (income >7000.00f)
	{
		flat_tax = 230.00;
		flex_tax = 0.06 * (income - 7000.0f);
	}

	tax_due = flat_tax + flex_tax;
	return tax_due;
}

int main()
{
	float income, tax_due;
	printf("Enter amount of taxable income: ");
	scanf("%f", &income);

	tax_due = income_tax(income);
	printf("Tax due: %.2f\n",tax_due);

    return 0;
}