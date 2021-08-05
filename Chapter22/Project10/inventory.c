#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert();
void search();
void update();
void print();
void erase();
void dump();
void restore();

int main(void)
{

    char code;
    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') // skips to the end of line
            ;
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'e':
            erase();
            break;
        case 'd':
            dump();
            break;
        case 'r':
            restore();
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code!\n");
        }
        printf("\n");
    }
}

// looks up a part number in inventory list
// returns pointer to the node
// returns NULL if part number is not found
struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

// prompts user for info about a new part, then inserts part in the list;
// ends prematurely if part already exists or space cannot be allocated
void insert()
{
    struct part *cur, *prev, *new_node;

    new_node = (struct part *)malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Malloc() failed!\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

// prompts user to enter part number, then looks up the part in the database.
// if it exists, prints name and quantity on hand, otherwise prints an error message
void search()
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);

    if (p == NULL)
        printf("Part not found!\n");
    else
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
}

// prompts the user to enter a part number.
// prints error message if part doesnt exist
// prompts user to enter change in quantity on hand and updates the database
void update()
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);

    if (p == NULL)
        printf("Part not found!\n");
    else
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
}

// prints a listing of all parts in the database,
// shows the part number, part name and quantity on hand;
void print()
{
    struct part *p = inventory;

    printf("Part Number\tPart Name\tQuantity on hand\n");
    if (p == NULL)
    {
        printf(" ----- No Parts Currently in Inventory ----- \n");
        return;
    }

    for (p = inventory; p != NULL; p = p->next)
    {
        printf("%7d\t\t%-25s%11d\n", p->number, p->name, p->on_hand);
    }
}

// erases a part from the database
void erase()
{
    int number;
    struct part *to_erase, *prev;

    printf("Enter part number: ");
    scanf("%d", &number);

    to_erase = find_part(number);

    if (to_erase == NULL)
    {
        printf("Part not found!\n"); // no such node found, no changes
        return;
    }

    // locate node to erase
    for (to_erase = inventory, prev = NULL;
         to_erase != NULL && to_erase->number != number;
         prev = to_erase, to_erase = to_erase->next)
        ;

    if (prev == NULL)
        inventory = inventory->next; // skip the first node
    else
    {
        prev->next = to_erase->next; // remove pointers to the node
        free(to_erase);              // free memory
    }

    //return inventory;
}

void dump()
{
    // open file for writing
    FILE *output_file;

    char output_filename[NAME_LEN];
    printf("Enter name of output file: ");
    scanf("%s", &output_filename);

    output_file = fopen(output_filename, "wb");

    if (output_file == NULL)
    {
        printf("Could not open file for writing!\n");
        exit(EXIT_FAILURE);
    }

    // save data
    struct part **p = &inventory;
    while (*p != NULL)
    {
        fwrite(*p, sizeof(struct part) - sizeof(struct part *), 1, output_file);
        p = &(*p)->next;
    }

    printf("All data was saved.\n");
    fclose(output_file);
}

void restore()
{
    // open file for reading
    FILE *input_file;

    char input_filename[NAME_LEN];
    printf("Enter name of input file: ");
    scanf("%s", &input_filename);

    input_file = fopen(input_filename, "rb");

    if (input_file == NULL)
    {
        printf("Could not open file for reading!\n");
        exit(EXIT_FAILURE);
    }

    // rebuild list
    struct part from_file;
    struct part **in_list;

    in_list = &inventory;

    while (fread(&from_file, sizeof(struct part) - sizeof(struct part *), 1, input_file) == 1)
    {
        *in_list = (part *)malloc(sizeof(struct part));
        if (*in_list == NULL)
        {
            printf("Malloc() failed.\n");
            exit(EXIT_FAILURE);
        }

        // copy data
        (*in_list)->number = from_file.number;
        strcpy((*in_list)->name, from_file.name);
        (*in_list)->on_hand = from_file.on_hand;

        (*in_list)->next = NULL;
        in_list = &(*in_list)->next; // next time, insert in the next node
    }

    printf("All data was restored.\n");
    fclose(input_file);
}