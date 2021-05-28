#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 20

int main()
{
    char smallest_word[MAX_LEN] = "0";
    char largest_word[MAX_LEN] = "0";
    char word[MAX_LEN];

    while (true)
    {
        printf("Enter word (with length 4 to terminate): ");
        gets(word);

        if (strlen(word) == 4)
        {
            if (smallest_word[0] == '0' || largest_word[0] == '0')
            {
                printf("Smallest word: %s\n", word);
                printf("Largest word: %s\n", word);
            }
            else
            {
                printf("Smallest word: %s\n", smallest_word);
                printf("Largest word: %s\n", largest_word);
            }
            break;
        }

        if (strlen(word) > strlen(largest_word))
            strcpy(largest_word, word);
        else
            strcpy(smallest_word, word);
    }
}