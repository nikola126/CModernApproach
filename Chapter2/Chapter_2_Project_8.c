#include <stdio.h>
int main()
{
	float loan, balance, interest_rate, monthly_rate, monthly_payment;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	balance = loan;

	printf("Interest rate: ");
	scanf("%f", &interest_rate);

	// convert to percentage and calculate monthly rate
	monthly_rate = (interest_rate / 100 )/ 12;

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	balance = balance - monthly_payment + balance * monthly_rate;
	printf("Balance remaining after first payment: $%.2f\n", balance);

	balance = balance - monthly_payment + balance * monthly_rate;
	printf("Balance remaining after second payment: $%.2f\n", balance);

	balance = balance - monthly_payment + balance * monthly_rate;
	printf("Balance remaining after third payment: $%.2f\n", balance);
}