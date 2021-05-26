#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// uses sleep() to "improve randomness"
int roll_dice(void)
{
	// generates two random numbers (between 1 and 6) and returns their sum
	srand((unsigned)time(NULL));
	int dice_one = rand() % 6;
	if (dice_one == 0)
		dice_one++;

	Sleep(800);

	int dice_two = rand() % 6;
	if (dice_two == 0)
		dice_two++;

	int sum = dice_one + dice_two;
	return sum;
}

bool play_game(void)
{
	bool game_over = false;
	bool point_reached = false;
	int roll, point;

	while (true)
	{
		roll = roll_dice();
		printf("You rolled: %d\n", roll);
		// INITIAL ROLL
		if (!point_reached)
		{
			if (roll == 7 || roll == 11)
			{
				printf("You win!\n");
				return true;
			}
			else if (roll == 2 || roll == 3 || roll == 12)
			{
				printf("You lose!\n");
				return false;
			}
			else
			{
				point_reached = true;
				point = roll;
				printf("YOUR POINT: %d\n", point);
			}
		}
		else
		// CHECK FOR SECOND POINT OR 7
		{
			if (roll == point)
			{
				printf("You win!\n");
				return true;
			}
			else if (roll == 7)
			{
				printf("You lose!\n");
				return false;
			}
		}
	}
}
int main()
{
	int player_wins = 0;
	int player_losses = 0;
	bool win = false;

	char user_choice = '0';
	while (true)
	{
		// get user choice
		printf("Play Craps? [y/n]: ");
		scanf("%c",&user_choice);
		while(getchar() != '\n'); // clean newline

		if (user_choice == 'y')
		{
			win = play_game();
			if (win)
				player_wins++;
			else
				player_losses++;
			win = false;
		}

		if (user_choice == 'n')
		{
			// show results and quit
			printf("Wins: %d\n", player_wins);
			printf("Losses: %d\n", player_losses);
			break;
		}
	}
}