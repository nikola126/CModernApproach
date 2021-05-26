#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void stack_underflow()
{
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
}

void stack_overflow()
{
    printf("Stack overflow!\n");
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

void push(char c)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

int main()
{
    char user_input; char out;
    do
    {
        user_input = getchar();
        switch (user_input)
        {
        case '(':
        case '{':
            push(user_input);
            break;
        case ')':
            out = pop();
            if (out != '(')
            {
                printf("Parentheses NOT nested properly!");
                exit(EXIT_FAILURE);
            }
            break;
        case '}':
            out = pop();
            if (out != '{')
            {
                printf("Braces NOT nested properly!");
                exit(EXIT_FAILURE);
            }
            break;
        }
    } while (user_input != '\n');

    if (is_empty())
        printf("Parentheses/braces are nested properly.\n");
}