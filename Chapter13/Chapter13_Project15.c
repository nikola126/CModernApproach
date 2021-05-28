#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

int contents[STACK_SIZE] = {0};
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

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
    {
        contents[top] = i;
        top++;
    }
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
    {
        top--;
        return contents[top];
    }
}

int evaluate_RPN_expression(const char *expression)
{
    int expression_length = strlen(expression);
    char input;
    int result = 0;

    for (int i = 0; i < expression_length - 1; i++)
    {
        input = expression[i];
        if (isdigit(input))
        {
            // operand, convert to int
            push(input - '0');
        }
        else
        {
            int oper_1, oper_2;
            // operators
            if (input != '=')
            {
                oper_2 = pop();
                oper_1 = pop();
            }
            // perform operation
            switch (input)
            {
            case '+':
                // push result in stack
                result = oper_2 + oper_1;
                push(result);
                break;
            case '-':
                result = oper_2 - oper_1;
                push(result);
                break;
            case '*':
                result = oper_2 * oper_1;
                push(result);
                break;
            case '/':
                result = oper_2 / oper_1;
                push(result);
                break;
            case '=':
                result = pop();
                printf("Result: %d\n", result);
                return result;
            default:
                printf("Incorrect Input\n");
                return 0;
            }
        }
    }
    return result;
}

int main()
{
    char expression[MAX_EXPRESSION_SIZE];
    printf("Polish Notation Calculator\n");
    printf("Enter Expression, Terminate with =\n");
    printf(">> ");
    gets(expression);

    printf("Result: %d\n", evaluate_RPN_expression(expression));
}