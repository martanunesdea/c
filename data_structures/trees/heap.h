/* 
 *      Title:  Header file for Heap
 *    Section:  Trees
 *     Author:  Marta Nunes de Abreu
 *       Date:  20/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#ifndef HEAP_H
#define HEAP_H
#define PQ_SIZE 100

typedef struct {
    int q[PQ_SIZE+1];     /* body of queue */
    int n;                /* number of queue elements */
} priority_queue;


void pq_init(priority_queue *q);
int pq_parent(int n);
int pq_young_child(int n);
void pq_swap(priority_queue *q, int p, int parent);
void bubble_up(priority_queue *q, int p);
void bubble_down(priority_queue *q, int p);

void pq_insert(priority_queue *q, int x);
int extract_min(priority_queue *q);
void make_heap(priority_queue *q, int s[], int n);
void print_heap(priority_queue *q, int n);
void my_heap_sort(int s[], int n);


#endif