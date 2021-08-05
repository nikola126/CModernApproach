#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100

int main()
{
	// input/output file
	FILE *fp_in;
	FILE *fp_out;
	char input_file_name[MAX_FILE_NAME_LEN];
	char *output_file_name;

	printf("Enter name of file to encrypt: ");
	scanf("%s", input_file_name);

	// try to open
	fp_in = fopen(input_file_name, "r");
	if (fp_in == NULL)
	{
		printf("File could not be opened for reading!\n");
		exit(EXIT_FAILURE);
	}

	// create output file (.enc)
	output_file_name = (char *)malloc(strlen(input_file_name) + 4 + 1);
	strcpy(output_file_name, input_file_name);
	strcat(output_file_name, ".enc");

	// try to open output file
	fp_out = fopen(output_file_name, "w");
	if (fp_out == NULL)
	{
		printf("File could not be opened for writing!\n");
		exit(EXIT_FAILURE);
	}

	// get the key
	int key = 0;
	printf("Insert key: ");
	scanf("%d", &key);
	// clear newline from buffer
	getchar();

	// convert to ciphertext
	// ci = (pi + k) % 26
	char c;
	while ((c = getc(fp_in)) != EOF)
	{
		if (isalpha(c) != 0)
		{
			// uppercase
			if (isupper(c))
				putc((((c - 'A') + key) % 26) + 'A', fp_out);
			// lowercase
			if (islower(c))
				putc((((c - 'a') + key) % 26) + 'a', fp_out);
		}
		else
			putc(c, fp_out);
	}

	// close files
	fclose(fp_in);
	fclose(fp_out);

	return 0;
}