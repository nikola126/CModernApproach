#include <stdio.h>

#define ERROR(format_string, ...) \
    fprintf(stderr, format_string, __VA_ARGS__)

int main()
{
    int index = 1;
    ERROR("Range error: index = %d\n", index);
    ERROR("Multiple arguments error: index out of bounds (%d,%d)\n", 5, 10);
}