#include <stdio.h>
#include <stdbool.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    // stores and returns departure and arrival time as minutes since midnight
    int dep_time_1 = 8 * 60 + 0;
    int dep_time_2 = 9 * 60 + 43;
    int dep_time_3 = 11 * 60 + 19;
    int dep_time_4 = 12 * 60 + 47;
    int dep_time_5 = 14 * 60 + 0;
    int dep_time_6 = 15 * 60 + 45;
    int dep_time_7 = 19 * 60 + 0;
    int dep_time_8 = 21 * 60 + 45;

    int arr_time_1 = 10 * 60 + 16;
    int arr_time_2 = 11 * 60 + 52;
    int arr_time_3 = 13 * 60 + 31;
    int arr_time_4 = 15 * 60 + 0;
    int arr_time_5 = 16 * 60 + 8;
    int arr_time_6 = 17 * 60 + 55;
    int arr_time_7 = 21 * 60 + 20;
    int arr_time_8 = 23 * 60 + 58;

    int diff_earlier, diff_later;

    if (desired_time < dep_time_1)
    {
        printf("Closest departure time is 8:00 arriving at 10:16\n");
        *departure_time = dep_time_1;
        *arrival_time = arr_time_1;
    }
    else if (dep_time_1 < desired_time && desired_time < dep_time_2)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_1;
            *arrival_time = arr_time_1;
        }
        else
        {
            *departure_time = dep_time_2;
            *arrival_time = arr_time_2;
        }
    }
    else if (dep_time_2 < desired_time && desired_time < dep_time_3)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_2;
            *arrival_time = arr_time_2;
        }
        else
        {
            *departure_time = dep_time_3;
            *arrival_time = arr_time_3;
        }
    }
    else if (dep_time_3 < desired_time && desired_time < dep_time_4)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_3;
            *arrival_time = arr_time_3;
        }
        else
        {
            *departure_time = dep_time_4;
            *arrival_time = arr_time_4;
        }
    }
    else if (dep_time_4 < desired_time && desired_time < dep_time_5)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_4;
            *arrival_time = arr_time_4;
        }
        else
        {
            *departure_time = dep_time_5;
            *arrival_time = arr_time_5;
        }
    }
    else if (dep_time_5 < desired_time && desired_time < dep_time_6)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_5;
            *arrival_time = arr_time_5;
        }
        else
        {
            *departure_time = dep_time_6;
            *arrival_time = arr_time_6;
        }
    }
    else if (dep_time_6 < desired_time && desired_time < dep_time_7)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_6;
            *arrival_time = arr_time_6;
        }
        else
        {
            *departure_time = dep_time_7;
            *arrival_time = arr_time_7;
        }
    }
    else if (dep_time_7 < desired_time && desired_time < dep_time_8)
    {
        diff_earlier = desired_time - dep_time_1;
        diff_later = dep_time_2 - desired_time;
        if (diff_earlier > diff_later)
        {
            *departure_time = dep_time_7;
            *arrival_time = arr_time_7;
        }
        else
        {
            *departure_time = dep_time_8;
            *arrival_time = arr_time_8;
        }
    }
    else
    {
        *departure_time = dep_time_8;
        *arrival_time = arr_time_8;
    }
}

int main()
{
    printf("Enter a 24-hour time: ");
    int user_input_h, user_input_m, user_mins;
    scanf("%d:%d", &user_input_h, &user_input_m);

    user_mins = user_input_h * 60 + user_input_m;

    int departure_mins, arrival_mins;
    find_closest_flight(user_mins, &departure_mins, &arrival_mins);

    printf("Closest departure time is %d:%d arriving at %d:%d \n", departure_mins / 60, departure_mins % 60, arrival_mins / 60, arrival_mins % 60);
}