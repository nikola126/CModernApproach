#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
int MAX_PARTS = 10; // changed from macro so it can be increased later
int num_parts = 0;

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} * inventory;

int find_part(int number);
void insert();
void search();
void update();
void print();

void quicksort(struct part a[], int, int);
int split(struct part a[], int, int);

int main(void)
{
    // inventory is allocated initially, and reallocated at every 10 parts
    inventory = (struct part *)malloc(sizeof(struct part) * MAX_PARTS);
    if (inventory == NULL)
    {
        printf("malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

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
        case 'q':
            return 0;
        default:
            printf("Illegal code!\n");
        }
        printf("\n");
    }
}

// looks up a part number in inventory array. returns array index if part number is found
int find_part(int number)
{
    for (int i = 0; i < num_parts; i++)
    {
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}

// prompts user for info about a new part, then inserts part in the database;
// ends prematurely and prints an error message if part already exists or inventory is full
void insert()
{
    int part_number;

    if (num_parts == MAX_PARTS)
    {
        // reallocates a new array with twice the size
        MAX_PARTS = MAX_PARTS * 2;
        struct part *temp = (part *)realloc(inventory, sizeof(struct part) * MAX_PARTS);

        if (temp == NULL)
        {
            printf("realloc() failed.\n");
            exit(EXIT_FAILURE);
        }

        inventory = (struct part *)temp;
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name:");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}

// prompts user to enter part number, then looks up the part in the database.
// if it exists, prints name and quantity on hand, otherwiste prints an error message
void search()
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

// prompts the user to enter a part number.
// prints error message if part doesnt exist
// prompts user to enter change in quantity on hand and updates the database
void update()
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);

    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

// prints a listing of all parts in the database, showing
// the part number, part name and quantity on hand;
// parts are printed in the order in which they were entered in the database
void print()
{
    // sort by part number
    quicksort(inventory, 0, num_parts - 1);

    printf("Part Number\tPart Name\tQuantity on hand\n");
    for (int i = 0; i < num_parts; i++)
    {
        printf("%7d\t\t%-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}

// sorts the parts by part number
void quicksort(struct part a[], int low, int high)
{

    int middle;

    if (low >= high)
        return;

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

// sorts the parts by part number
// used by quicksort()
int split(struct part a[], int low, int high)
{

    struct part part_element = a[low];

    for (;;)
    {
        while (low < high && part_element.number <= a[high].number)
            high--;
        if (low >= high)
            break;
        a[low++] = a[high];

        while (low < high && a[low].number <= part_element.number)
            low++;
        if (low >= high)
            break;
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}