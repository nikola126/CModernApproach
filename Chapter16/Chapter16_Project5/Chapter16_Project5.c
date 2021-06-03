#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    struct flight
    {
        int departure_time;
        int arrival_time;
    } flights_arr[] = {
        {8 * 60 + 0, 10 * 60 + 16},
        {9 * 60 + 43, 11 * 60 + 52},
        {11 * 60 + 19, 13 * 60 + 31},
        {12 * 60 + 47, 15 * 60 + 0},
        {14 * 60 + 0, 16 * 60 + 8},
        {15 * 60 + 45, 17 * 60 + 55},
        {19 * 60 + 0, 21 * 60 + 20},
        {21 * 60 + 45, 23 * 60 + 58}};

    int flights_available = sizeof(flights_arr) / sizeof(flights_arr[0]);

    int user_input_h, user_input_m, user_mins;

    printf("There are %d flights available.\n", flights_available);
    printf("Enter a 24-hour time [00:00] >> ");

    scanf("%d:%d", &user_input_h, &user_input_m);

    user_mins = user_input_h * 60 + user_input_m;

    // check earliest
    if (user_mins < flights_arr[0].departure_time)
    {
        printf("Closest departure time is %d arriving at %d EARLIEST\n",
               flights_arr[0].departure_time,
               flights_arr[0].arrival_time);
        return 0;
    }

    // check latest
    if (user_mins > flights_arr[flights_available - 1].departure_time)
    {
        printf("Closest departure time is %d arriving at %d LATEST\n",
               flights_arr[flights_available - 1].departure_time,
               flights_arr[flights_available - 1].arrival_time);
        return 0;
    }

    // check rest
    int difference = 0, min = 1000, min_index = 0;

    for (int i = 0; i < flights_available; i++)
    {

        difference = abs(flights_arr[i].departure_time - user_mins);
        if (difference < min)
        {
            min = difference;
            min_index = i;
        }
    }

    int output_dep_h = flights_arr[min_index].departure_time / 60;
    int output_dep_m = flights_arr[min_index].departure_time % 60;
    int output_arr_h = flights_arr[min_index].arrival_time / 60;
    int output_arr_m = flights_arr[min_index].arrival_time % 60;

    printf("Closest departure time is %d:%d arriving at %d:%d\n",
           output_dep_h, output_dep_m,
           output_arr_h, output_arr_m);

    return 0;
}