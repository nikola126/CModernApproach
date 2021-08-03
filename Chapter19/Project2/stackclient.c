#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main()
{
    char user_input;
    int out;
    int result;
    int oper1, oper2;

    Stack s;
    s = create();

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
            push(s, user_input - '0'); // convert to int
            break;
        // operators
        case '+':
            oper1 = pop(s);
            oper2 = pop(s);
            result = oper1 + oper2;
            push(s, result);
            break;
        case '-':
            oper1 = pop(s);
            oper2 = pop(s);
            result = oper2 - oper1;
            push(s, result);
            break;
        case '*':
            oper1 = pop(s);
            oper2 = pop(s);
            result = oper1 * oper2;
            push(s, result);
            break;
        case '/':
            oper1 = pop(s);
            oper2 = pop(s);
            result = oper2 / oper1;
            push(s, result);
            break;
        case '=':
            result = pop(s);
            printf("Result: %d\n",result);
            return 0;
        default:
            printf("Incorrect Input!\n");
            return 0;
        }
    } while (true);


}