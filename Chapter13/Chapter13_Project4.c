#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // requires command-line arguments
    // prints them in reverse order
    for (int i = argc; i >= 0; i--)
        printf("%s\n", argv[i]);
}