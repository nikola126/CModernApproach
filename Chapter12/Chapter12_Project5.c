#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int max_length = 100;
    char input, terminating_character = '.';
    char sentence[max_length] = {0};
    int i = 0;

    // save sentence
    printf("Enter a sentence (NO terminating characters, except at the end!):\n>>");
    do
    {
        input = getchar();

        // save terminating character separately
        if (input == '.' || input == '!' || input == '?')
        {
            terminating_character = input;
        }
        else
        {
            sentence[i] = input;
            i++;
        }
    } while (input != '.' && input != '!' && input != '?');

    int sentence_length = i;

    // using pointers
    // loop back and print words
    char *from_end;
    char *reversed;
    int current_word_len = 0;

    printf("Reversed: \n");
    // loop from end to start
    for (from_end = sentence + sentence_length - 1; from_end >= sentence; from_end--)
    {
        current_word_len++;
        if (*from_end == ' ')
        {
            // when a space is found, loop from last found space to end of word
            reversed = from_end + 1;
            for (reversed = from_end; reversed < from_end + current_word_len; reversed++)
                printf("%c", *reversed);
            current_word_len = 0;
        }
    }

    // no spaces left, print from beginning to first space to add the first word
    printf(" ");
    char *from_start;
    for (from_start = sentence; from_start <= sentence + sentence_length - 1; from_start++)
    {
        if (*from_start == ' ')
            break;
        else
            printf("%c", *from_start);
    }

    // also print the terminating char
    printf("%c\n", terminating_character);
}