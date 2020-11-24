/* 
 *      Title:  Heap
 *    Section:  Trees
 *     Author:  Marta Nunes de Abreu
 *       Date:  20/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>

#define PQ_SIZE 100

typedef struct {
    int q[PQ_SIZE+1];     /* body of queue */
    int n;                /* number of queue elements */
} priority_queue;

void pq_init(priority_queue *q)
{
    q->n = 0;
}

int pq_parent(int n)
{
    if (n == 1)
        return (-1);
    else
        return( (int)n/2 );     /* implicity round the number */

}

int pq_young_child(int n)
{
    return( 2*n );
}

void pq_swap(priority_queue *q, int p, int parent)
{
    int temp = q->q[p];
    q->q[p] = q->q[parent];
    q->q[parent] = temp;
}

void bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1)
        return;
    
    if (q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }

}


void pq_insert(priority_queue *q, int x)
{
    if( q->n >= PQ_SIZE)
        printf("Warning: priority queue overflow insert x=%d\n", x);
    else {
        q->n = (q->n) + 1;
        q->q[ q->n ] = x;
        bubble_up(q, q->n);
    }
}

void make_heap(priority_queue *q, int s[], int n)
{
    int i;      /* counter */
    pq_init(q);
    for(int i = 0; i < n; i++)
    {
        pq_insert(q, s[i]);
    }
}

void print_heap(priority_queue *q, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf(" %d \n", q->q[i+1]);
    }
}

int main(void)
{
    priority_queue *q;
    q = (priority_queue*) malloc(sizeof q);
    
    int array_size = 4;
    int s[4] = {23, 32, 18, 19};
    
    make_heap(q, s, array_size);
    print_heap(q, array_size);

    return 0;
}