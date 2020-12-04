/* 
 *      Title:  Prim's Minimum Spanning Tree Algorithm
 *    Section:  Graphs
 *    Summary:  A greedy algorithm to find the minimum spanning tree
 *     Author:  Marta Nunes de Abreu
 *       Date:  02/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"


void prim (struct graph *g, int start)
{
    struct adj_list *p;
    bool intree[MAX+1];
    int distance[MAX+1];

    int v;
    int w;
    int weight;
    int dist;

    /* initialise arrays */
    for (int i = 0; i <= g->n_vertices; i++)
    {
        intree[i] = FALSE;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;

    while ( intree[v] == FALSE) {
        intree[v] = TRUE;
        p = g->array[v].head;
        while ( p != NULL ) {
            w = p->head->next;
            weight = p->weight;
            if ( (distance[w] > weight) && ( intree[w] == FALSE) )
            {
                distance[w] = weight;
                parent[w] = v;
            }
            p = p->head->next;
        }
        v = 1;
        dist = MAXINT;

        for (int i = 1; i <= g->n_vertices; i++) {
            if ( (intree[i] == FALSE) && (dist > distance[i]) ) {
                dist = distance[i];
                v = i;
            }
        }
    }

}

int main ( void )
{
    return 0;
}