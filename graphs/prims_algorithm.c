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

#define MAXINT 1000

void prim (struct graph *g, int start)
{
    struct adj_node *p;
    bool intree[MAX+1];             /* represent set of vertices in MST */
    int distance[MAX+1];            /* distance of edges */ 
    int parent[g->n_vertices];      /* store MST */
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
            w = p->dest;
            weight = p->weight;
            if ( (distance[w] > weight) && ( intree[w] == FALSE) )
            {
                distance[w] = weight;
                parent[w] = v;
                printf("Setting parent of %d to be %d\n", w, v);
            }
            p = p->next;
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
    // initialise graph object
    int vertices = 3; 
    struct graph* g;
    g = graph_initialize(vertices); 
    
    graph_insert_edge(g, 0, 2);
    graph_insert_edge(g, 0, 3);
    graph_insert_edge(g, 3, 1);
    graph_insert_edge(g, 1, 2);

    // print the adjacency list representation of the above graph 
    graph_print(g); 
    prim(g, 2);

    return 0;
}