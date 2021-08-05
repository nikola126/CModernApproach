#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR_LEN 150
#define MAX_WORDS 10

int main(void)
{
    // read string
    char input_str[MAX_STR_LEN];
    fgets(input_str, MAX_STR_LEN, stdin);

    // terminate it
    input_str[strlen(input_str) - 1] = '\0';

    // keep pointers to tokens here
    char* token_arr[MAX_WORDS];

    // get first word
    token_arr[0] = strtok(input_str, " ");
    int words_found = 1;

    // keep tokenizing until strtok returns
    while ((token_arr[words_found] = strtok(NULL, " ")) != NULL)
        words_found += 1;

    // print (reversed)
    for (int i = words_found - 1; i >= 0; i--)
    {
        printf("%s ", token_arr[i]);
    }
    printf("\n");
}