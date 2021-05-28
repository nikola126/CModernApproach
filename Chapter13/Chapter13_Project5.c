#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int total = 0;
    // requires command-line arguments
    // assumes them to be ints and returns their sum
    for (int i = 0; i < argc; i++)
        total += atoi(argv[i]);
    
    printf("Total: %d",total);
}