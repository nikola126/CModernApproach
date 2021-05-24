#include <stdio.h>
#include <stdbool.h>

int main()
{
	// no arrays and loops yet

	printf("Enter a 24-hour time: ");
	int user_input_h, user_input_m, user_mins;
	scanf("%d:%d", &user_input_h, &user_input_m);

	user_mins = user_input_h * 60 + user_input_m;

	float dep_time_1 = 8 * 60 + 0;
	float dep_time_2 = 9 * 60 + 43;
	float dep_time_3 = 11 * 60 + 19;
	float dep_time_4 = 12 * 60 + 47;
	float dep_time_5 = 14 * 60 + 0;
	float dep_time_6 = 15 * 60 + 45;
	float dep_time_7 = 19 * 60 + 0;
	float dep_time_8 = 21 * 60 + 45;

	float diff_earlier, diff_later;

	if (user_mins < dep_time_1)
	{
		printf("Closest departure time is 8:00 arriving at 10:16\n");
	}
	else if (dep_time_1 < user_mins && user_mins < dep_time_2)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 8:00 arriving at 10:16\n");
		else
			printf("Closest departure time is 9:43 arriving at 11:52\n");
	}
	else if (dep_time_2 < user_mins && user_mins < dep_time_3)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 9:43 arriving at 11:52\n");
		else
			printf("Closest departure time is 11:19 arriving at 13:31\n");
	}
	else if (dep_time_3 < user_mins && user_mins < dep_time_4)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 11:19 arriving at 13:31\n");
		else
			printf("Closest departure time is 12:47 arriving at 15:00\n");
	}
	else if (dep_time_4 < user_mins && user_mins < dep_time_5)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 12:47 arriving at 15:00\n");
		else
			printf("Closest departure time is 14:00 arriving at 16:08\n");
	}
	else if (dep_time_5 < user_mins && user_mins < dep_time_6)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 14:00 arriving at 16:08\n");
		else
			printf("Closest departure time is 15:45 arriving at 17:55\n");
	}
	else if (dep_time_6 < user_mins && user_mins < dep_time_7)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 15:45 arriving at 17:55\n");
		else
			printf("Closest departure time is 19:00 arriving at 21:20\n");
	}
	else if (dep_time_7 < user_mins && user_mins < dep_time_8)
	{
		diff_earlier = user_mins - dep_time_1;
		diff_later = dep_time_2 - user_mins;
		if (diff_earlier > diff_later)
			printf("Closest departure time is 19:00 arriving at 21:20\n");
		else
			printf("Closest departure time is 21:45 AM arriving at 23:58\n");
	}
	else
	{
		printf("Closest departure time is 21:45 AM arriving at 23:58\n");
	}
}