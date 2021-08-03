#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node
{
    Item data;
    struct node *next;
};

struct queue_type
{
    struct node *first;
    struct node *last;

    int len;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = (queue_type *)malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create(): queue could not be created.");
    printf("Queue created\n");
    q->first = NULL;
    q->last = NULL;
    q->len = 0;

    return q;
}

void destroy(Queue q)
{
    empty_queue(q);
    free(q);
}

void empty_queue(Queue q)
{
    while (!is_empty(q))
    {
        pop(q);
    }
}

// insert at the end
void push(Queue q, Item p)
{
    struct node *new_node = (node *)malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push(): Queue is full.");

    new_node->data = p;
    new_node->next = NULL;

    if (is_empty(q))
    {
        // if it's the first node, first and last are the same
        q->first = new_node;
        q->last = new_node;
        q->len += 1;
    }
    else
    {
        // the last element is the new node
        q->last = new_node;
        q->last->next = new_node;
        q->len += 1;
    }
}

// remove from beginning
Item pop(Queue q)
{
    if (!is_empty(q))
    {
        // get the first node
        struct node *to_pop = q->first;

        // if first node in queue
        if (q->first == q->last)
        {
            q->first = NULL;
            q->last = NULL;
        }
        else
        // the next node is now the first
        {
            q->first = q->first->next;
        }

        // save the data and free the first node
        Item popped_data = to_pop->data;
        free(to_pop);
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
        return q->first->data;
    }
    else
        terminate("Cannot return value, queue is empty.");
}

// return last item
Item get_last(Queue q)
{
    if (!is_empty(q))
    {
        return q->last->data;
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