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
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], time_str[3], msg_str[MSG_LEN+1];
    int day, time, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("No space left!\n");
            break;
        }

        printf("Enter day, 24-hr time and reminder (day 0 to terminate): ");

        // Get Day
        scanf("%2d", &day);
        if (day == 0)
            break;
        else if (day < 0 || day > 31)
        {
            printf("Invalid Day! Reminder ignored...\n");
            // clear buffer and try again
            while (getchar() != '\n');
            continue;
        }
        else
            sprintf(day_str,"%2d",day);

        // Get Time
        scanf("%2d", &time);
        if (time < 0 || time > 24)
        {
            printf("Invalid time! Reminder ignored...\n");
            // clear buffer and try again
            while (getchar() != '\n');
            continue;
        }
        else
            sprintf(time_str,"%2d",time);

        // Get Reminder
        read_line(msg_str,MSG_LEN);
        
        // SORTING
		// if time is not in order, remember i
		for (i = 0; i < num_remind; i++)
			if (strcmp(time_str, reminders[i]) < 0)
				break;
		// and move everything else
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);


		// if day is not in order, remember i
		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		// and move everything else
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);
        
        // Save all to reminders array
        strcpy(reminders[i],day_str);
        strcat(reminders[i]," ");
        strcat(reminders[i],time_str);
        strcat(reminders[i],msg_str);

        num_remind++;
    }
    
    printf("\nDay Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n",reminders[i]);
    return 0;
}