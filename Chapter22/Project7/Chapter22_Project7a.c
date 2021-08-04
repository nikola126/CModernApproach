#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// compress a file using run-length encoding
int main(int argc, char *argv[])
{
	FILE *source;
	FILE *destination;
	char *destination_file_name;

	if (argc != 2)
	{
		printf("usage: compress_file filename.txt\n");
		exit(EXIT_FAILURE);
	}

	source = fopen(argv[1], "rb");

	if (source == NULL)
	{
		printf("%s can't be opened!\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// append extension of the output file
	destination_file_name = malloc(strlen(argv[1]) + 4 + 1);
	strcpy(destination_file_name, argv[1]);
	strcat(destination_file_name, ".rle");

	// open file for writing
	if ((destination = fopen(destination_file_name, "wb")) == NULL)
	{
		printf("File %s cannot be written\n", destination_file_name);
		exit(EXIT_FAILURE);
	}

	unsigned char reps;	   // unsigned, repetitions are positive values only
	long int position = 0; // ftell returns a long int
	char current_byte, next_byte;

	// read byte by byte
	while (fread(&current_byte, sizeof(char), 1, source) > 0)
	{
		reps = 1;				  // reset reps
		position = ftell(source); // remember the current position

		// while current byte is the same as the next, increment reps
		while (fread(&next_byte, sizeof(char), 1, source) > 0 && current_byte == next_byte)
		{
			reps++;
		}

		// if a different byte is reached, write the reps as byte and the current byte to the output file
		fwrite(&reps, sizeof(unsigned char), 1, destination);
		fwrite(&current_byte, sizeof(unsigned char), 1, destination);

		// return to the previous position
		fseek(source, position + (reps - 1), SEEK_SET);
	}

	fclose(source);
	fclose(destination);
	return 0;
}