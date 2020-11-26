/*
 *          Title: Queue
 *        Summary: Data structure to be used by mergesort 
 *        Section: Mergesort/Sorting
 *         Author: Marta
 *           Date: 22/11/2020
 */
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define max 100
static int queue[max+1], head, tail;


void enqueue(struct queue *buffer, int new_value)
{
    buffer->queue[tail++] = new_value;
    if (tail > max)
    {
        // reset queue
        tail = 0;
    }
}
int dequeue(struct queue *buffer)
{
    int top = (buffer->head)++;
    if (buffer->head > max)
    {
        // reset queue
        head = 0;
    }
    return top;
}
void init_queue(struct queue *buffer)
{
    buffer->head = 0;
    buffer->tail = 0;
}

int empty_queue(struct queue *buffer)
{
    return buffer->head == buffer->tail;
}

int headq(struct queue *buffer)
{
    return ( buffer->head );
}