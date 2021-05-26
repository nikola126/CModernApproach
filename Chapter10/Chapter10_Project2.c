#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs; // can be 0, 1, 2

void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS])
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
            card_exists[rank][suit] = false;
    }

    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;

    while (cards_read < NUM_CARDS)
    {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch)
        {
        case '0':
            exit(EXIT_SUCCESS);
        case '2':
            rank = 0;
            break;
        case '3':
            rank = 1;
            break;
        case '4':
            rank = 2;
            break;
        case '5':
            rank = 3;
            break;
        case '6':
            rank = 4;
            break;
        case '7':
            rank = 5;
            break;
        case '8':
            rank = 6;
            break;
        case '9':
            rank = 7;
            break;
        case 't':
        case 'T':
            rank = 8;
            break;
        case 'j':
        case 'J':
            rank = 9;
            break;
        case 'q':
        case 'Q':
            rank = 10;
            break;
        case 'k':
        case 'K':
            rank = 11;
            break;
        case 'a':
        case 'A':
            rank = 12;
            break;
        default:
            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch)
        {
        case 'c':
        case 'C':
            suit = 0;
            break;
        case 'd':
        case 'D':
            suit = 1;
            break;
        case 'h':
        case 'H':
            suit = 2;
            break;
        case 's':
        case 'S':
            suit = 3;
            break;
        default:
            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;

        if (bad_card)
            printf("Bad card! Ignored...\n");
        else if (card_exists[rank][suit])
            printf("Duplicate card! Ignored...\n");
        else
        {
            // Card is OK
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS])
{
    int num_consecutive = 0;
    int rank, suit;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    // Check for flush
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[suit] == NUM_CARDS)
            flush = true;

    // Check for straight
    rank = 0;
    while (num_in_rank[rank] == 0)
        rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consecutive++;
    if (num_consecutive == NUM_CARDS)
    {
        straight = true;
        return;
    }

    // Check for 4 of a kind, 3 of a kind, pairs
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs++;
    }
}

void print_result()
{
    if (straight && flush)
        printf("Straight flush!");
    else if (four)
        printf("Four of a kind!");
    else if (three && pairs == 1)
        printf("Full house!");
    else if (flush)
        printf("Flush!");
    else if (straight)
        printf("Straight!");
    else if (three)
        printf("Three of a kind!");
    else if (pairs == 2)
        printf("Two pairs!");
    else if (pairs == 1)
        printf("A pair!");
    else
        printf("High card!");
    
    printf("\n\n");
}

int main()
{
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];

    for (;;)
    {
        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit);
        print_result();
    }
}