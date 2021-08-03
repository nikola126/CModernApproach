#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main()
{
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    printf("Length of s1 is: %d\n", Length(s1));
    printf("Length of s2 is: %d\n", Length(s2));

    push(s1, 1);
    push(s1, 2);

    printf("Length of s1 is: %d\n", Length(s1));
    printf("Length of s2 is: %d\n", Length(s2));

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printf("Length of s1 is: %d\n", Length(s1));
    push(s2, n);
    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printf("Length of s1 is: %d\n", Length(s1));
    push(s2, n);

    destroy(s1);

    while (!is_empty(s2))
    {
        printf("Popped %d from s2\n", pop(s2));
        printf("Length of s2 is: %d\n", Length(s2));
    }

    push(s2, 3);
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