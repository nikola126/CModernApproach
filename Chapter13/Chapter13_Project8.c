#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 20

int compute_scrabble_word(const char *word)
{
    int i = 0;
    int value = 0;
    char letter = word[i];

    while (letter != '\0')
    {
        letter = toupper(letter);
        switch (letter)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
            value += 1;
            break;
        case 'D':
        case 'G':
            value += 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            value += 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            value += 4;
            break;
        case 'K':
            value += 5;
            break;
        case 'J':
        case 'X':
            value += 8;
            break;
        case 'Q':
        case 'Z':
            value += 10;
            break;
        default:
            printf("Invalid word!\n");
            return 0;
            break;
        }

        // look at next letter
        letter = word[++i];
    }

    return value;
}

int main()
{
    char num_char;
    int value = 0;
    printf("Enter a word: ");
    char word[MAX_WORD_LEN];
    gets(word);

    value = compute_scrabble_word(word);
    printf("Value: %d\n", value);
}