#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	printf("Enter a 24-hour time: ");
	int user_input_h, user_input_m;
	int user_mins;
	scanf("%d:%d", &user_input_h, &user_input_m);

	user_mins = user_input_h * 60.0 + user_input_m;

	int dep_time_1 = 8 * 60 + 0;
	int dep_time_2 = 9 * 60 + 43;
	int dep_time_3 = 11 * 60 + 19;
	int dep_time_4 = 12 * 60 + 47;
	int dep_time_5 = 14 * 60 + 0;
	int dep_time_6 = 15 * 60 + 45;
	int dep_time_7 = 19 * 60 + 0;
	int dep_time_8 = 21 * 60 + 45;

	int departure_times[] = { dep_time_1,dep_time_2, dep_time_3, dep_time_4, dep_time_5, dep_time_6, dep_time_7, dep_time_8 };

	int arr_time_1 = 10 * 60 + 16;
	int arr_time_2 = 11 * 60 + 52;
	int arr_time_3 = 13 * 60 + 31;
	int arr_time_4 = 15 * 60 + 0;
	int arr_time_5 = 16 * 60 + 8;
	int arr_time_6 = 17 * 60 + 55;
	int arr_time_7 = 21 * 60 + 20;
	int arr_time_8 = 23 * 60 + 58;

	int arrival_times[] = { arr_time_1,arr_time_2, arr_time_3, arr_time_4, arr_time_5, arr_time_6, arr_time_7, arr_time_8 };

	int min = (int) fabs((double)user_mins - (double)departure_times[0]);
	int dep_difference;
	int min_index;

	for (int i = 0; i < 7; i++)
	{
		dep_difference = user_mins - departure_times[i];
		// handle negative numbers
		if (dep_difference < 0)
			dep_difference *= -1;
		if (dep_difference <= min)
		{
			min_index = i;
			min = dep_difference;
		}
	}

	int output_dep_m = departure_times[min_index] % 60;
	int output_dep_h = (departure_times[min_index] - output_dep_m) / 60;

	int output_arr_m = arrival_times[min_index] % 60;
	int output_arr_h = (arrival_times[min_index] - output_arr_m) / 60;

	printf("Closest departure is at %d:%d with arrival time %d:%d (index %d)\n", output_dep_h, output_dep_m, output_arr_h, output_arr_m, min_index);
}