#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_DIGITS 10
#define HEIGHT 3
#define WIDTH (MAX_DIGITS * 4) // one more column for a blank space between digits

char digits_arr[HEIGHT][WIDTH];

//	0
// 1 3
//  2
// 4 6
//  5

//                            0  1  2  3  4  5  6
const int segments[10][7] = {{1, 1, 0, 1, 1, 1, 1},  // 0
                             {0, 0, 0, 1, 0, 0, 1},  // 1
                             {1, 0, 1, 1, 1, 1, 0},  // 2
                             {1, 0, 1, 1, 0, 1, 1},  // 3
                             {0, 1, 1, 1, 0, 0, 1},  // 4
                             {1, 1, 1, 0, 0, 1, 1},  // 5
                             {1, 1, 1, 0, 1, 1, 1},  // 6
                             {1, 0, 0, 1, 0, 0, 1},  // 7
                             {1, 1, 1, 1, 1, 1, 1},  // 8
                             {1, 1, 1, 1, 0, 1, 1}}; // 9
//                            0  1  2  3  4  5  6

void process_digit(int digit, int position)
{
    // loop through digits arr but only through specific indexes
    int segments_index = 0;       // resets after every placed digit
    int column_offset = position; // should increment by 4 after every placed digit
    bool usable_segment = true;   // should reset after every placed digit
    int digit_required = digit;   // affects which row of segments will be looked at

    for (int i = 0; i < 3; i++)
    {
        for (int j = column_offset; j < column_offset + 3; j++)
        {
            usable_segment = true;
            // indexes [0][0] and [0][2] should always be skipped, a 3x3 grid is used and any values there dont look good
            if (i == 0 && j == 0 + column_offset)
                usable_segment = false;
            if (i == 0 && j == 0 + column_offset + 2)
                usable_segment = false;

            if (usable_segment)
            {
                if (segments[digit_required][segments_index] == 1)
                {
                    if (segments_index == 0 || segments_index == 2 || segments_index == 5)
                        digits_arr[i][j] = '_';
                    else
                        digits_arr[i][j] = '|';
                }

                segments_index++;
            }
        }
    }
}

void clear_digits_array(void)
{
    // initializes and resets the array
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
            digits_arr[i][j] = ' ';
    }
}

void print_digits_array(void)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
            printf("%c", digits_arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    clear_digits_array();
    char input = '0';
    int offset = 0;

    printf("Enter number (max %d digits):\n>> ", MAX_DIGITS);
    do
    {
        if (offset == MAX_DIGITS * 4)
        {
            printf("Maximum offset reached.");
            printf(" Only %d digits will be displayed.\n",MAX_DIGITS);
            break;
        }
        input = getchar();

        if (isdigit(input))
        {
            process_digit(input - '0', offset);
            // by default, every next digit (3 columns wide)
            // 1 empty column is added for visibility
            offset += 4;
        }
    } while (input != '\n');

    print_digits_array();
    clear_digits_array();
}