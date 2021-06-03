#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void stack_underflow()
{
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
}

void stack_overflow()
{
    printf("Stack overflow!\n");
    printf("Expression is too complex!\n");
    exit(EXIT_FAILURE);
}

void make_empty()
{
    top = 0;
}

bool is_empty()
{
    return top == 0;
}

bool is_full()
{
    return top == STACK_SIZE;
}

void push(int c)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}