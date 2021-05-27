#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool duplicate(int rank, int suit, int hand[NUM_CARDS][2])
{
    for (int i = 0; i < NUM_CARDS; i++)
    {
        if (hand[i][0] == rank && hand[i][1] == suit)
            return true; // a card with the same rank and suit is found
    }
    return false;
}

void read_cards(int hand[NUM_CARDS][2])
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    // Initialize array
    for (int card = 0; card < NUM_CARDS; card++)
    {
        hand[card][0] = -1; // rank
        hand[card][1] = -1; // suit
    }

    while (cards_read < NUM_CARDS)
    {
        bad_card = false;

        printf("Enter a card [%d/%d]: ", cards_read + 1, NUM_CARDS);

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
        else if (duplicate(rank, suit, hand))
            printf("Duplicate card! Ignored...\n");
        else
        {
            // Card is OK
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

void analyze_hand(int hand[NUM_CARDS][2], bool *royal_flush, bool *straight, bool *ace_low_straight, bool *flush, bool *four, bool *three, int *pairs)
{
    *royal_flush = false;
    *straight = false;
    *flush = false;
    *four = false;
    *three = false;
    pairs = 0;

    // sort hand for easier checks
    int idx_smallest, swap_suit, swap_rank;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        idx_smallest = i;

        for (int j = i + 1; j < NUM_CARDS; j++)
        {
            if (hand[j][0] < hand[idx_smallest][0])
                idx_smallest = j;
        }

        swap_rank = hand[i][0];
        swap_suit = hand[i][1];
        hand[i][0] = hand[idx_smallest][0];
        hand[i][1] = hand[idx_smallest][1];
        hand[idx_smallest][0] = swap_rank;
        hand[idx_smallest][1] = swap_suit;
    }

    // Check for royal flush (ace,king,queen,jack,ten of the same suit)
    // ranks 8 to 12
    if (hand[0][0] == 8 && hand[NUM_CARDS - 1][0] == 12)
        *royal_flush = true;

    // Check for flush (all from the same suit)
    int required_suit = hand[0][1];
    *flush = true;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        if (hand[i][1] != required_suit)
        {
            *flush = false;
            break;
        }
    }

    // Check for straight (consecutive ranks)
    *straight = true;
    for (int i = 1; i < NUM_CARDS; i++)
    {
        if (hand[i][0] - hand[i - 1][0] != 1)
        {
            *straight = false;
            break;
        }
    }

    // Check for ace-low straight (consecutive ranks and ace)
    if (hand[NUM_CARDS - 1][0] == 12) // there is ace at the end
        *ace_low_straight = true;
    for (int i = 1; i < NUM_CARDS - 1; i++)
    {
        if (hand[i][0] - hand[i - 1][0] != 1) // first four are consecutive
        {
            *ace_low_straight = false;
            break;
        }
    }

    // Check for 4 of a kind, 3 of a kind, pairs (same rank)
    int rank, suit;
    int card = 0, current_rank = 0, streak = 0;
    while (card < NUM_CARDS)
    {
        rank = hand[card][current_rank];
        streak = 0;

        do
        {
            // increase streak while rank is the same and there are more cards to check
            streak++;
            card++;
        } while (card < NUM_CARDS && hand[card][current_rank] == rank);

        // check if any pairs/threes/fours are found
        switch (streak)
        {
        case 2:
            pairs++;
            break;
        case 3:
            *three = true;
            break;
        case 4:
            *four = true;
            break;
        }
    }
}

void print_result(bool *royal_flush, bool *straight, bool *ace_low_straight, bool *flush, bool *four, bool *three, int *pairs)
{
    if (royal_flush) // highest priority
        printf("Royal flush!");
    else if (straight && flush)
        printf("Straight flush!");
    else if (four)
        printf("Four of a kind!");
    else if (three && *pairs == 1)
        printf("Full house!");
    else if (flush)
        printf("Flush!");
    else if (ace_low_straight)
        printf("Ace-low straight!");
    else if (straight)
        printf("Straight!");
    else if (three)
        printf("Three of a kind!");
    else if (*pairs == 2)
        printf("Two pairs!");
    else if (*pairs == 1)
        printf("A pair!");
    else
        printf("High card!");

    printf("\n\n");
}

int main()
{

    int hand[NUM_CARDS][2];
    // [0][0] - rank of first card
    // [0][1] - suit of first card

    bool royal_flush, straight, ace_low_straight, flush, four, three;
    int pairs; // can be 0, 1, 2

    for (;;)
    {
        read_cards(hand);
        analyze_hand(hand, &royal_flush, &straight, &ace_low_straight, &flush, &four, &three, &pairs);
        print_result(&royal_flush, &straight, &ace_low_straight, &flush, &four, &three, &pairs);
    }
}