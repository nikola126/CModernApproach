#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main()
{
    Queue q1;
    int n;

    q1 = create(2);
    printf("Length of q1 is: %d\n", get_length(q1));

    push(q1, 10);
    printf("Pushed %d to q1\n", 10);
    printf("Length of q1 is: %d\n", get_length(q1));

    n = pop(q1);
    printf("Popped %d from q1\n", n);
    printf("Length of q1 is: %d\n", get_length(q1));

    push(q1, 5);
    printf("Pushed %d to q1\n", 5);
    push(q1, 6);
    printf("Pushed %d to q1\n", 6);
    push(q1, 7);
    printf("Pushed %d to q1\n", 7);
    push(q1, 8);
    printf("Pushed %d to q1\n", 8);

    printf("Length of q1 is: %d\n", get_length(q1));
    printf("First item in q1 is: %d\n", get_first(q1));
    printf("Last item in q1 is: %d\n", get_last(q1));

    return 0;
}