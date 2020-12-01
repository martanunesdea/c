/*
 *          Title: Queue
 *        Section: Array-based data structures
 *        Summary: Restricted access data structure with FIFO operations
 *         Author: Marta
 *           Date: 22/11/2020
 *       Compiler: clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "queue.h"

#define max     100
#define OK      0
#define NOK     1

void queue_initialize(struct queue *buffer)
{
    // set contents of queue to 0
    memset(buffer, 0, sizeof(struct queue));
    // set head and tail of queue to 0;
    buffer->head = 0;
    buffer->tail = 0;
}

int queue_put(struct queue *buffer, int new_value)
{
    buffer->queue[buffer->tail] = new_value;
    if (buffer->tail == max)
    {
        printf("\nError: Queue is full\n");
        return NOK;
    }
    else
    {
        buffer->tail += 1;
    }
    return OK;
}

int queue_get(struct queue *buffer)
{
    int head = buffer->queue[buffer->head];

    if (buffer->head == max)
    {
        printf("\nError: Queue is full\n");
        // assume queue stores positives only
        // signal there was error with -1
        return (-1);
    }
    else
    {
        buffer->head += 1;
    }    

    return head;
}

int queue_empty(struct queue *buffer)
{
    return buffer->head == buffer->tail;
}

int get_queue_head(struct queue *buffer)
{
    return ( buffer->head );
}
int get_queue_tail(struct queue *buffer)
{
    return ( buffer->tail );
}

int test_queue_empty(struct queue *buffer)
{
    if( queue_empty(buffer) )
        return OK;
    else
        return NOK;
    
}

int test_queue_puts(struct queue *buffer, int item_total)
{   
    int error = 0;
    for (int i = 0; i < item_total; i++)
    {
        error = queue_put(buffer, i);
        if (error)
            return NOK;
    }
    return OK;
}

int test_queue_gets(struct queue *buffer, int item_total)
{
    int value;
    for (int i = 0; i < item_total; i++)
    {
        value = queue_get(buffer);
        if( value == -1)
            return NOK;
    }
    return OK;
}