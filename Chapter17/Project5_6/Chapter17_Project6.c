#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 20

// reads a string and terminates it with \\0
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

// used as comparison function by qsort()
int compare_strings(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

int main()
{
    char *word = NULL;
    char **words_array = NULL;

    int num_words = 0;
    int size = 1;
    int word_length;

    // words are saved in an array of pointers
    // double pointer to char must be used to access the array
    words_array = (char **)malloc(sizeof(char *));
    if (words_array == NULL)
    {
        printf("malloc() fail!\n");
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        word = (char *)malloc(MAX_WORD_LEN + 1);
        if (word == NULL)
        {
            printf("malloc() fail!\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter word (press Enter to stop): ");
        word_length = read_line(word, MAX_WORD_LEN);
        if (word_length == 0)
        {
            break;
        }

        *(words_array + num_words) = word; // save last word in the array
        num_words++;

        // double the size of the array after each new word
        if (size == num_words)
        {
            size = size * 2;
            words_array = (char **)realloc(words_array, sizeof(char *) * size);
            if (words_array == NULL)
            {
                printf("realloc() fail!\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    qsort(words_array, num_words, sizeof(char *), compare_strings);

    printf("All words:\n");
    for (int i = 0; i < num_words; i++)
    {
        printf("%s\n", *(words_array + i));
    }
    printf("\n");
}