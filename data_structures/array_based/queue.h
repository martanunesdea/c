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

int put(struct queue *buffer, int new_value);
int get(struct queue *buffer);
void init_queue(struct queue *buffer);
int is_queue_empty(struct queue *buffer);
int get_queue_head(struct queue *buffer);
