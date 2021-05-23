#include <stdio.h>
int main()
{
	// arrays not covered yet!
	int a0, a1, a2, a3;
	int b0, b1, b2, b3;
	int c0, c1, c2, c3;
	int d0, d1, d2, d3;
	printf("Enter the numbers from 1 to 16 in any order (space separated):\n>>");
	
	scanf("%d %d %d %d",&a0,&a1,&a2,&a3);
	scanf("%d %d %d %d",&b0,&b1,&b2,&b3);
	scanf("%d %d %d %d",&c0,&c1,&c2,&c3);
	scanf("%d %d %d %d",&d0,&d1,&d2,&d3);

	printf("%2d %2d %2d %2d\n", a0, a1, a2, a3);
	printf("%2d %2d %2d %2d\n", b0, b1, b2, b3);
	printf("%2d %2d %2d %2d\n", c0, c1, c2, c3);
	printf("%2d %2d %2d %2d\n", d0, d1, d2, d3);

	int row_sum_1 = a0 + a1 + a2 + a3;
	int row_sum_2 = b0 + b1 + b2 + b3;
	int row_sum_3 = c0 + c1 + c2 + c3;
	int row_sum_4 = d0 + d1 + d2 + d3;

	int col_sum_1 = a0 + b0 + c0 + d0;
	int col_sum_2 = a1 + b1 + c1 + d1;
	int col_sum_3 = a2 + b2 + c2 + d2;
	int col_sum_4 = a3 + b3 + c3 + d3;

	int diag_sum_1 = a0 + b1 + c2 + d3;
	int diag_sum_2 = d0 + c1 + b2 + a3;

	printf("Row sums: %d %d %d %d\n",row_sum_1,row_sum_2,row_sum_3,row_sum_4);
	printf("Column sums: %d %d %d %d\n", col_sum_1, col_sum_2, col_sum_3, col_sum_4);
	printf("Diagonal sums: %d %d\n", diag_sum_1, diag_sum_2);
    return 0;
}