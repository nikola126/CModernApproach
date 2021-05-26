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

int main()
{
    char user_input;
    int out;
    int result;
    int oper1, oper2;

    printf("Polish Notation Calculator\n");
    printf("Enter Space-separated Expression, Terminate with =\n");
    printf(">> ");
    do
    {
        scanf(" %c", &user_input);
        switch (user_input)
        {
        // operand
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            push(user_input - '0'); // convert to int
            break;
        // operators
        case '+':
            oper1 = pop();
            oper2 = pop();
            result = oper1 + oper2;
            push(result);
            break;
        case '-':
            oper1 = pop();
            oper2 = pop();
            result = oper2 - oper1;
            push(result);
            break;
        case '*':
            oper1 = pop();
            oper2 = pop();
            result = oper1 * oper2;
            push(result);
            break;
        case '/':
            oper1 = pop();
            oper2 = pop();
            result = oper2 / oper1;
            push(result);
            break;
        case '=':
            result = pop();
            printf("Result: %d\n",result);
            return 0;
        default:
            printf("Incorrect Input!\n");
            return 0;
        }
    } while (true);


}