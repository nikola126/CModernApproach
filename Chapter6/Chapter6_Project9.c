#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	float loan, balance, interest_rate, monthly_rate, monthly_payment;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	balance = loan;

	printf("Interest rate: ");
	scanf("%f", &interest_rate);
	// convert to percentage and calculate monthly rate
	monthly_rate = (interest_rate / 100) / 12;

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	int payments;
	printf("Enter number of payments: ");
	scanf("%d", &payments);

	for (int i = 0; i < payments; i++)
	{
		balance = balance - monthly_payment + balance * monthly_rate;
		printf("Balance remaining after payment (%d): $%.2f\n", i+1, balance);
	}
}