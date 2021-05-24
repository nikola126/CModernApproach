#include <stdio.h>
#include <stdbool.h>

int main()
{
	int gcd, remainder, m, n;
	printf("Enter two space separated integers: ");
	scanf("%d %d", &m, &n);

	if (n == 0)
	{
		printf("Greatest common divisor: %d\n", m);
		return 0;
	}
	while (n != 0)
	{	
		remainder = m % n;
		m = n;
		n = remainder;
	}
	printf("Greatest common divisor: %d\n", m);
}