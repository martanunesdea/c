/*
 *          Title: queue.h
 *        Summary: Header for Queue source code
 *        Section: Mergesort/Sorting
 *         Author: Marta
 *           Date: 22/11/2020
 */
#include <stdlib.h>
#include <stdio.h>

#define max 100

struct queue {
    int queue[max+1];
    int head;
    int tail;
};

void enqueue(struct queue *buffer, int new_value);
int dequeue(struct queue *buffer);
void init_queue(struct queue *buffer);
int empty_queue(struct queue *buffer);
int headq(struct queue *buffer);
