#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: fcopy.exe testing.txt output.txt\n");
        exit(EXIT_FAILURE);
    }

    // try to open files
    FILE *fp_in;
    FILE *fp_out;

    if ((fp_in = fopen(argv[1], "rb")) == NULL)
    {
        printf("File %s could not be opened!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp_out = fopen(argv[2], "wb")) == NULL)
    {
        printf("File %s could not be opened!\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int bytes_read;
    char write_buffer[BLOCK_SIZE];

    // read in blocks of 512 (at most)
    while ((bytes_read = fread(write_buffer, sizeof(write_buffer[0]), BLOCK_SIZE, fp_in)) > 0)
    {
        // write to file
        fwrite(write_buffer, sizeof(write_buffer[0]), bytes_read, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
}