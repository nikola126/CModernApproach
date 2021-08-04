#ifndef READLINE_H
#define READLINE_H

// skips leading white-space chars, then reads the remainder
// of the input line and stores it in a string;
// truncates the line if its length exceeds n;
// returns number of characters stored

int read_line(char str[], int n);
#endif // !READLINE_H