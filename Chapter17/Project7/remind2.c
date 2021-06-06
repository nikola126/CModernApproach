#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50 // max number of reminders
#define MSG_LEN 60    // max length of reminder message

int read_line(char str[], int n);

int main()
{
    struct vstring
    {
        int len;
        char chars[];
    };

    struct vstring *reminders[MAX_REMIND];

    char day_str[3], msg_str[MSG_LEN + 1];
    int day, last_index, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("No space left!\n");
            break;
        }

        printf("Enter day and reminder (0 to terminate): ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day); // save day in day_str
        read_line(msg_str, MSG_LEN);  // save msg in msg_str

        // reorder by day
        for (last_index = 0; last_index < num_remind; last_index++)
        {
            if (strcmp(day_str, reminders[last_index]->chars) < 0)
                break; // remember last_index
        }
        for (j = num_remind; j > last_index; j--)
        {
            reminders[j] = reminders[j - 1];
        }

        // allocate memory for new reminder
        reminders[last_index] = malloc(sizeof(struct vstring) + 2 + strlen(msg_str) + 1);
        strcpy(reminders[last_index]->chars, day_str);
        strcat(reminders[last_index]->chars, msg_str);

        num_remind += 1;
    }

    // Print all
    printf("\nDay Reminder\n");
    for (last_index = 0; last_index < num_remind; last_index++)
    {
        printf(" %s\n", reminders[last_index]->chars);
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i] = ch;
            i++;
        }
    }
    str[i] = '\0';
    return i;
}