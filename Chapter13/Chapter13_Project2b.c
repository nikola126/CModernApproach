#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_REMIND 50
#define MSG_LEN 60

// saves a line in str[], up to [n] characters
// returns the number of characters in line
int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int main()
{
    // data arrays
    char reminders[MAX_REMIND][MSG_LEN];
    int dates[MAX_REMIND] = {0}; // stores (DAY * 100) + HOUR
    // input
    char current_str[MSG_LEN];
    int current_day, current_hour, i, j, num_remind = 0;
    // used in sorting
    int swap_date;
    char swap_str[MSG_LEN];

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("No space left!\n");
            break;
        }
        printf("Enter day, 24-hr time and reminder (day 0 to terminate): ");

        // Get Day
        scanf("%2d", &current_day);
        if (current_day == 0)
            break;
        else if (current_day < 1 || current_day > 31)
        {
            printf("Invalid Day! Reminder ignored...\n");
            // clear buffer and try again
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            dates[num_remind] += (current_day * 100);
        }

        // Get Hour
        scanf("%2d", &current_hour);
        if (current_hour == 0)
            break;
        else if (current_hour < 0 || current_hour > 23)
        {
            printf("Invalid Hour! Reminder ignored...\n");
            // clear buffer and try again
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            dates[num_remind] += (current_hour);
        }

        // Get Reminder
        read_line(current_str, MSG_LEN);
        strcpy(reminders[num_remind], current_str);

        num_remind++;
    }

    // Sort by date
    for (i = 0; i < num_remind; i++)
    {
        for (j = 0; j < num_remind - i - 1; j++)
        {
            if (dates[j] > dates[j + 1])
            {
                // swap date
                swap_date = dates[j];
                dates[j] = dates[j + 1];
                dates[j + 1] = swap_date;
                // swap reminder
                strcpy(swap_str, reminders[j]);
                strcpy(reminders[j], reminders[j + 1]);
                strcpy(reminders[j + 1], swap_str);
            }
        }
    }

    // Print all
    printf("Day\tHour\tReminder:\n");
    for (i = 0; i < num_remind; i++)
        printf("%d\t%d\t%s\n", dates[i] / 100, dates[i] % 100, reminders[i]);

    return 0;
}