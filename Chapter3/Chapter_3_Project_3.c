#include <stdio.h>
int main()
{
	int gsi, group_id, pub_code, item_number, check;
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d", &gsi, &group_id, &pub_code, &item_number, &check);

	printf("GSI prefix: %d\n", gsi);
	printf("Group identifier: %d\n", group_id);
	printf("Publisher code: %d\n", pub_code);
	printf("Item number: %d\n", item_number);
	printf("Check digit: %d\n", check);

    return 0;
}