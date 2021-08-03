#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

// typedef int Item; // char when adding symbols { } ( )

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, const void *p);
void *pop(Stack s);
int Length(Stack s);

#endif