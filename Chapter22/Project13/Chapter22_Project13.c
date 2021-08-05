#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2)
    {
        printf("usage: flights flights.dat\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("File could not be opened!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a 24-hour time: ");
    int user_input_h, user_input_m, user_mins;
    scanf("%d:%d", &user_input_h, &user_input_m);

    user_mins = user_input_h * 60 + user_input_m;

    // read minutes from arrival time, calculate difference
    // if a minimum is found, print the departure time
    int dep_time_h, dep_time_m;
    int arr_time_h, arr_time_m;
    int dep_minutes;
    int difference;
    int min = 1000;
    int min_h, min_m;
    int min_arr_h, min_arr_m;

    char input_string[8];
    int items_read;
    char next_char;
    while (true)
    {
        // dep_time arr_time
        // 00:00 00:00
        fgets(input_string, 25, fp);

        items_read = sscanf(input_string, "%d:%d %d:%d\n", &dep_time_h, &dep_time_m, &arr_time_h, &arr_time_m);

        if (items_read != 4)
        {
            printf("Incorrect format in %s!\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        dep_minutes = dep_time_h * 60 + dep_time_m;
        difference = abs(dep_minutes - user_mins);

        if (difference < min)
        {
            min = difference;
            min_h = dep_time_h;
            min_m = dep_time_m;
            min_arr_h = arr_time_h;
            min_arr_m = arr_time_m;
        }
        else
        {
            printf("Closest departure time is at %d:%d, arriving at %d:%d\n", min_h, min_m, min_arr_h, min_arr_m);
            break;
        }
    }
}