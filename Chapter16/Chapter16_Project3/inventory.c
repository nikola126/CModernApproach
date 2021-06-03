#include <stdio.h>
#include "inventory.h"
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

int find_part(struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);

void quicksort(struct part a[], int, int);
int split(struct part a[], int, int);

int main(void)
{
    // local part array
    struct part inventory[MAX_PARTS];
    int num_parts = 0;

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
            insert(inventory, &num_parts);
            break;
        case 's':
            search(inventory, num_parts);
            break;
        case 'u':
            update(inventory, num_parts);
            break;
        case 'p':
            print(inventory, num_parts);
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
int find_part(struct part inventory[], int num_parts, int number)
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
void insert(struct part inventory[], int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS)
    {
        printf("Database is full. Cannot add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(inventory, *num_parts, part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter part name:");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);

    (*num_parts)++;
}

// prompts user to enter part number, then looks up the part in the database.
// if it exists, prints name and quantity on hand, otherwiste prints an error message
void search(struct part inventory[], int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);

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
void update(struct part inventory[], int num_parts)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);

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
void print(struct part inventory[], int num_parts)
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