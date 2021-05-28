#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_PLANETS 9
#define MAX_NAME_LEN 10

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    int i, j, k = 0;

    char lower_argc[MAX_NAME_LEN];
    char lower_name[MAX_NAME_LEN];

    for (i = 1; i < argc; i++)
    {
        // convert every input string to lower-case before comparing
        k = 0;
        strcpy(lower_argc, argv[i]);
        while (lower_argc[k] != '\0')
        {
            lower_argc[k] = tolower(lower_argc[k]);
            k++;
        }

        for (j = 0; j < NUM_PLANETS; j++)
        {
            // convert every planet name to lower-case before comparing
            k = 0;
            strcpy(lower_name, planets[j]);
            while (lower_name[k] != '\0')
            {
                lower_name[k] = tolower(lower_name[k]);
                k++;
            }

            //printf("Comparing %s with %s\n", lower_argc, lower_name);

            if (strcmp(lower_argc, lower_name) == 0)
            {
                printf("%s is planet %d\n", planets[j], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS)
            printf("%s is not a planet!\n", argv[i]);
    }
}