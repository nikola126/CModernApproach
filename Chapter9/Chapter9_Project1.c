#include <stdio.h>

#define N 10

void selection_sort(int a[], int arr_len)
{
	// treat first element as max element
	int max = a[0];
	int max_location = 0;

	// termination check
	if (arr_len == 1)
		return;

    // find a bigger element and move it to last position
	for (int i = 0; i < arr_len; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			max_location = i;
		}
	}

	// swap
	int swap = a[max_location];
	a[max_location] = a[arr_len-1];
	a[arr_len-1] = swap;

	// call itself recursively to sort the rest of the array
	selection_sort(a, arr_len - 1);
}

int main()
{
    int arr[N] = {0};
    printf("Enter %d elements to be sorted: \n",N);
    for (int i = 0; i < N; i++)
    {
        printf(">> ");
        scanf("%d",&arr[i]);
    }
    
    selection_sort(arr,N);

    printf("In sorted order: ");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

    return 0;
}