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

void bubble_down(priority_queue *q, int p)
{
    int c;          /* child index */
    int i;          /* counter */
    int min_index;  /* index of lightest child */

    c = pq_young_child(p);
    min_index = p;

    for( i = 0; i <= 1; i++)
    {
        if ( (c+i) <= q->n)
        {
            if ( q->q[min_index] > q->q[c+i])
                min_index = c+i;
        }
    }

    if (min_index != p)
    {
        pq_swap(q,p,min_index);
        bubble_down(q, min_index);
    }

}

int extract_min(priority_queue *q)
{
    int min = -1;
    if (q->n <= 0)
    {
        printf("Warning: empty priority queue. \n");
    }
    else
    {
        min = q->q[1];
        q->q[1] = q->q[ q-> n];
        q->n = q->n - 1;
        bubble_down(q, 1);
    }
    return min; 
}

void make_heap(priority_queue *q, int s[], int n)
{
    int i;              /* counter */
    pq_init(q);
    for(int i = 0; i < n; i++)
    {
        pq_insert(q, s[i]);
    }
}


void print_heap(priority_queue *q, int n)
{
    printf("\n\n -----  Heap ------ \n");
    for(int i = 0; i < n; i++)
    {
        printf("\t %d \n", q->q[i+1]);
    }
    printf("\n ----------------- \n");
}


void my_heap_sort(int s[], int n)
{
    int i;              /* counters */
    priority_queue q;   /* heap for heapsort */

    make_heap(&q, s, n);
    print_heap(&q, n);
    
    for (i = 0; i < n; i++)
    {
        s[i] = extract_min(&q);
    }

    print_heap(&q, n);
}

int main(void)
{
    priority_queue *q;
    q = (priority_queue*) malloc(sizeof q);
    
    const int array_size = 5;
    int s[array_size] = {23, 32, 10, 21, 19};
    
    make_heap(q, s, array_size);
    print_heap(q, array_size);

    extract_min(q);
    print_heap(q, 4);

    int array[5] = {3, 5, 6, 1, 9};
    my_heap_sort(array, 5);

    return 0;
}