/*
 *          Title: queue.h
 *        Summary: Header for Queue source code
 *        Section: Mergesort/Sorting
 *         Author: Marta
 *           Date: 22/11/2020
 *       Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>

#define max 100

struct queue {
    int queue[max+1];
    int head;
    int tail;
};

int queue_put(struct queue *buffer, int new_value);
int queue_get(struct queue *buffer);
void queue_initialize(struct queue *buffer);
int queue_empty(struct queue *buffer);
int get_queue_head(struct queue *buffer);
int get_queue_tail(struct queue *buffer);
