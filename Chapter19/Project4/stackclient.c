#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main()
{
    Stack s1, s2;
    char * n;

    s1 = create();
    s2 = create();

    printf("Length of s1 is: %d\n", Length(s1));
    printf("Length of s2 is: %d\n", Length(s2));

    char test[] = "Test string";

    push(s1, "test");
    push(s2, "test");

    printf("Length of s1 is: %d\n", Length(s1));
    printf("Length of s2 is: %d\n", Length(s2));

    n = pop(s1);
    printf("Popped %s from s1\n", n);
    printf("Length of s1 is: %d\n", Length(s1));
    push(s2, "test");
    n = pop(s1);
    printf("Popped %s from s1\n", n);
    printf("Length of s1 is: %d\n", Length(s1));
    push(s2, "test");

    destroy(s1);

    while (!is_empty(s2))
    {
        printf("Popped %s from s2\n", pop(s2));
        printf("Length of s2 is: %d\n", Length(s2));
    }

    push(s2, "test");
    printf("Length of s2 is: %d\n", Length(s2));
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");
    printf("Length of s1 is: %d\n", Length(s1));

    destroy(s2);

    return 0;
}