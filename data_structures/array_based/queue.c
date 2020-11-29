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

void init_queue(struct queue *buffer)
{
    // set contents of queue to 0
    memset(buffer, 0, sizeof(struct queue));
    // set head and tail of queue to 0;
    buffer->head = 0;
    buffer->tail = 0;
}

int put(struct queue *buffer, int new_value)
{
    buffer->queue[buffer->tail] = new_value;
    buffer->tail += 1;

    if (buffer->tail > max)
    {
        printf("\nError: Queue is full\n");
        return 1;
    }
    return 0;
}
int get(struct queue *buffer)
{
    int top = buffer->queue[buffer->head];
    buffer->queue[buffer->head] = buffer->queue[(buffer->head)+1];
    if (buffer->head > max)
    {
        printf("\nError: Queue is full\n");
        return (-1);
    }
    return top;
}

int is_queue_empty(struct queue *buffer)
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
    return OK;
}

int test_queue_puts(struct queue *buffer, int item_total)
{   
    int error = 0;
    for (int i = 0; i < item_total; i++)
    {
        error = put(buffer, i);
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
        value = get(buffer);
        if( value == -1)
            return NOK;
    }
    return OK;
}

int main(void)
{
    struct queue *buffer;
    buffer = (struct queue*) malloc(sizeof *buffer); 
    init_queue(buffer);
    //put(buffer, 1);
    //put(buffer, 2);
    int error = put(buffer, 3);
    int value = get(buffer);
    printf("value at front of queue %d \n", value);

    int items_to_put = 90;
    int items_to_get = items_to_put;
    
    if( test_queue_puts(buffer, items_to_put) == OK)
    {
        printf("\nPassed: test_queue_puts\n");
    }
    if( test_queue_gets(buffer, 104) == OK)
    {
        printf("\nPassed: test_queue_gets\n");
    }
}