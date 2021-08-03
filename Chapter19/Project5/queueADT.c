#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type
{
    Item data[MAX_QUEUE_SIZE];

    int empty_index;
    int next_to_remove;
    int len;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = (Queue) malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create(): queue could not be created.");
    printf("Queue created\n");
    q->empty_index = 0;
    q->next_to_remove = 0;
    q->len = 0;

    return q;
}

void destroy(Queue q)
{
    free(q);
}

// insert at the end
void push(Queue q, Item p)
{
    // check if above max length
    if (q->len == MAX_QUEUE_SIZE)
        terminate("Cannot push: Above maximum queue size.");
    else
    {
        // save data at the next empty index
        q->data[q->empty_index] = p;
        q->empty_index += 1;
        q->len += 1;
    }
}

// remove from beginning
Item pop(Queue q)
{
    if (!is_empty(q))
    {
        // save data
        Item popped_data = q->data[q->next_to_remove];
        // change indices
        q->next_to_remove += 1;
        q->len -= 1;
        return popped_data;
    }
    else
        terminate("Cannot pop(), queue is empty.");
}

// return first item
Item get_first(Queue q)
{
    if (!is_empty(q))
    {
        return q->data[q->next_to_remove];
    }
    else
        terminate("Cannot return value, queue is empty.");
}

// return last item
Item get_last(Queue q)
{
    if (!is_empty(q))
    {
        return q->data[q->empty_index - 1];
    }
    else
        terminate("Cannot return value, queue is empty.");
}

bool is_empty(Queue q)
{
    return (q->len == 0);
}

int get_length(Queue q)
{
    return q->len;
}