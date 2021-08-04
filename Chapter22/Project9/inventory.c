#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

// using saved files from Project 8
// saved in plaintext!
// different parts are ignored

int main(int argc, char *argv[])
{
    FILE *in_fp1, *in_fp2, *out_fp;

    if (argc != 4)
    {
        printf("usage: merge infile1 infile2 outfile\n");
        exit(EXIT_FAILURE);
    }

    if ((in_fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("%s can not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((in_fp2 = fopen(argv[2], "r")) == NULL)
    {
        printf("%s can not be opened.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((out_fp = fopen(argv[3], "w")) == NULL)
    {
        printf("%s can not be opened.\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    int parts_in_file_1, parts_in_file_2, parts_in_file;
    fscanf(in_fp1, "%d\n", &parts_in_file_1);
    fscanf(in_fp2, "%d\n", &parts_in_file_2);

    printf("Parts in file 1: %d\n", parts_in_file_1);
    printf("Parts in file 2: %d\n", parts_in_file_2);

    int parts_in_file_diff = abs((parts_in_file_1 - parts_in_file_2));
    printf("Difference: %d\n", parts_in_file_diff);

    int min_parts;
    if (parts_in_file_1 < parts_in_file_2)
        min_parts = parts_in_file_1;
    else
        min_parts = parts_in_file_2;

    int part1_number, part2_number;
    int part1_on_hand, part2_on_hand;
    char part1_name[NAME_LEN], part2_name[NAME_LEN];

    for (int i = 0; i < min_parts; i++)
    {
        // read from both
        fscanf(in_fp1, "%d %s %d\n", &part1_number, &part1_name, &part1_on_hand);
        fscanf(in_fp2, "%d %s %d\n", &part2_number, &part2_name, &part2_on_hand);

        printf("From file 1: %d %s %d\t", part1_number, part1_name, part1_on_hand);
        printf("From file 2: %d %s %d\n", part2_number, part2_name, part2_on_hand);

        if (part1_number < part2_number)
        {
            fprintf(out_fp, "%d %s %d\n", part1_number, part1_name, part1_on_hand);
            parts_in_file += 1;
        }
        else if (part2_number < part1_number)
        {
            fprintf(out_fp, "%d %s %d\n", part2_number, part2_name, part2_on_hand);
            parts_in_file += 1;
        }
        else
        {
            // part numbers are equal
            if (strcmp(part1_name, part2_name) != 0)
                printf("Names don't match for part %d; using the name %s\n", part1_number, part1_name);
            fprintf(out_fp, "%d %s %d\n", part2_number, part2_name, part1_on_hand + part2_on_hand);
            parts_in_file += 1;
        }
    }

    // if any parts left
    printf("Adding leftover parts...\n");
    if (parts_in_file_1 > parts_in_file_2)
    {
        // copy rest of file 1 to output file
        for (int i = 0; i < parts_in_file_diff; i++)
        {
            fscanf(in_fp1, "%d %s %d\n", &part1_number, &part1_name, &part1_on_hand);
            fprintf(out_fp, "%d %s %d\n", part1_number, part1_name, part1_on_hand);
            printf("From file 1: %d %s %d\n", part1_number, part1_name, part1_on_hand);
            parts_in_file += 1;
        }
    }
    else
    {
        // copy rest of file 2 to output file
        for (int i = 0; i < parts_in_file_diff; i++)
        {
            fscanf(in_fp2, "%d %s %d\n", &part2_number, &part2_name, &part2_on_hand);
            fprintf(out_fp, "%d %s %d\n", part2_number, part2_name, part2_on_hand);
            printf("From file 2: %d %s %d\n", part2_number, part2_name, part2_on_hand);
            parts_in_file += 1;
        }
    }

    printf("Parts in combined file: %d\n", parts_in_file);
    fseek(out_fp, 0, SEEK_SET);
    fprintf(out_fp, "%d\n", parts_in_file);

    fclose(in_fp1);
    fclose(in_fp2);
    fclose(out_fp);
    return 0;
}