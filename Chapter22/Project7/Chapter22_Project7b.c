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
		printf("usage: decompress_file filename.txt.rle\n");
		exit(EXIT_FAILURE);
	}

	source = fopen(argv[1], "rb");

	if (source == NULL)
	{
		printf("%s can't be opened!\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// check for correct extension
	int source_file_name_length = strlen(argv[1]);
	printf("name length: %d\n", source_file_name_length);
	char source_file_name_extension[] = "rle";

	int j = 0;
	for (int i = source_file_name_length - 3; i < source_file_name_length; i++)
	{
		if (argv[1][i] != source_file_name_extension[j])
		{
			printf("Incorrect file extension! (.%s)\n", source_file_name_extension);
			exit(EXIT_FAILURE);
		}
		j += 1;
	}

	// remove extension of the output file
	destination_file_name = malloc(strlen(argv[1]) - 4);
	strncpy(destination_file_name, argv[1], strlen(argv[1]) - 4);

	printf("Output file name is: %s\n", destination_file_name);

	// open file for writing
	if ((destination = fopen(destination_file_name, "wb")) == NULL)
	{
		printf("File %s cannot be opened\n", destination_file_name);
		exit(EXIT_FAILURE);
	}

	unsigned char reps;	   // unsigned, repetitions are positive values only
	long int position = 0; // ftell returns a long int!
	char current_byte, next_byte;

	// read byte by byte
	while (fread(&current_byte, sizeof(char), 1, source) > 0)
	{
		// every second byte is a "reps" byte
		if (position % 2 == 0)
			reps = current_byte;
		else
		{
			// "content" byte
			for (int i = 0; i < reps; i++)
			{
				// write reps bytes of content
				fwrite(&current_byte, sizeof(unsigned char), 1, destination);
			}
		}
		position++;
	}

	fclose(source);
	fclose(destination);
	return 0;
}