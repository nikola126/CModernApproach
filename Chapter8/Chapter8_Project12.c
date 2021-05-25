#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int values[] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
	int arr_size = sizeof(values);

	char input;
	int value = 0;
	printf("Enter a word: ");

	while ((input = getchar()) != '\n')
	{
		input = tolower(input);
		for (int i = 0; i < arr_size; i++)
		{
			if (input == alphabet[i])
				value += values[i];
		}
	}

	printf("Value: %d\n", value);
}