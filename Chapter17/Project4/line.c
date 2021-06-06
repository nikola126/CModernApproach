#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

int line_len = 0;
int num_words = 0;

struct node
{
    char word[20];
    struct node *next;
};

struct node *line = NULL;

// free() the entire linked list, reset line length and number of words
void clear_line(void)
{
    struct node *current;

    while (line != NULL)
    {
        current = line;    // store current node in current
        line = line->next; // next node is in line
        free(current);     // free current node
    }

    line_len = 0;
    num_words = 0;
}

// malloc() a new word and change all ->next's to point up to it
void add_word(const char *word)
{
    // allocate new word
    struct node *new_word = (struct node *)malloc(sizeof(struct node) + strlen(word) + 1);
    if (new_word == NULL)
    {
        printf("Error in malloc()!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_word->word, word);
    new_word->next = NULL;

    // add to list
    struct node **previous = &line; // double pointer makes line modifiable

    // reorder previous nodes so the final one points to the new word
    while (*previous != NULL)
    {
        previous = &(*previous)->next;
    }
    *previous = new_word;
    line_len += strlen(word);

    // increment line_len and num_words
    if (num_words > 0)
        line_len += 1; // additional space between words
    num_words += 1;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i;
    bool alternate_spacing = true;
    int char_count = 0;

    struct node *entry = line;
    extra_spaces = space_remaining();

    while (char_count < line_len && entry != NULL)
    {
        printf("%s", entry->word);
        if (num_words > 1)
        {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (int i = 0; i <= spaces_to_insert + 1; i++)
            {
                putchar(' ');
            }
            extra_spaces = extra_spaces - spaces_to_insert;
        }

        char_count += strlen(entry->word) + 1;
        num_words--;

        // advance through linked list
        entry = entry->next;
    }

    putchar('\n');
}

void flush_line(void)
{
    int i;
    struct node *entry = line;

    if (line_len > 0)
    {
        // increment i and advance through linked list
        for (int i = 0; entry != NULL; i++, entry = entry->next)
        {
            if (i > 0 && entry->next != NULL)
                putchar(' ');
            printf("%s", entry->word);
        }
    }
    printf("\n");
    clear_line();
}