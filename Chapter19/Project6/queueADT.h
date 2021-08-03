#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create(unsigned int);
void destroy(Queue q);
void push(Queue q, Item p);
Item pop(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);
bool is_empty(Queue q);
int get_length(Queue q);

#endif