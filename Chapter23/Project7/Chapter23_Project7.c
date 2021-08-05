#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char c;
    bool end_reached = false;
    int sentences = 0;

    while ((c = getchar()) != EOF)
    {
        // check for end of sentence
        if (c == '.' || c == '?' || c == '!')
        {
            end_reached = true;
            // skip whitespace check
            continue;
        }

        // check for following whitespace
        if (end_reached && (c == ' ' || c == '\n' || c == '\t'))
        {
            // sentence is found, reset booleans
            end_reached = false;
            sentences += 1;
        }
        else
        {
            // no following whitespace, dont count sentence
            end_reached = false;
        }
    }

    printf("There are %d sentences.\n", sentences);
}