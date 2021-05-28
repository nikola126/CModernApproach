#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main()
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *suit_names[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    const char *rank_names[] = {"Two", "Three", "Four", "Five",
                                "Six", "Seven", "Eight", "Nine",
                                "Ten", "Jack", "Queen", "King", "Ace"};

    srand((unsigned)time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:\n");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank])
        {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%s of %s\n", rank_names[rank], suit_names[suit]);
        }
    }
    printf("\n");
}