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
#include "traversal.h"
#define MAXINT 1000

void prim (graph *g, int start)
{
    printf("\n\n----Prim's-----\n\n");
    int i;
    edgenode *p;
    bool intree[MAXV+1];             /* represent set of vertices in MST */
    int distance[MAXV+1];            /* distance of edges */ 
    int parent[g->nvertices];      /* store MST */
    int v;
    int w;
    int weight;
    int dist;

    /* initialise arrays */
    for (i = 0; i <= g->nvertices; i++)
    {
        intree[i] = false;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;

    while ( intree[v] == false) {
        printf("\nTaking vertex %d \n", v);
        intree[v] = true;
        p = g->edges[v];
        while ( p != NULL ) {
            w = p->y;
            weight = p->weight;
            printf("\nFrom %d: \t looking at adjacent %d with weight %d \n", v, w, weight);

            if ( (distance[w] > weight) && ( intree[w] == false) )
            {
                printf("Distance of element %d = %d now set to %d\n", w, distance[w], weight);
                distance[w] = weight;
                printf("Parent of element %d = %d now set to %d\n", w, parent[w], v);
                parent[w] = v;
                printf("%d -> %d \n", v, w);
            }
            p = (edgenode *) p->next;
        }
        v = 1;
        dist = MAXINT;
        for (i = 1; i <= g->nvertices; i++) {
            // look for smallest edge from vertex 
            if ( (intree[i] == false) && (dist > distance[i]) ) {
                printf("current dist is %d \t distance of element %d = %d \n", dist, i, distance[i]);
                dist = distance[i];
                v = i;   
            }
        }
    }

    printf("\n ------ parent string ----- \n\n");
    for (int i = 1; i <= g->nvertices; i++)
    {
        if ( parent[i] == (-1))
        {
            printf(" ( ) - ");
        }
        else {
            printf(" (%d) - ", parent[i]);
        }
    }

}

int main ( void )
{
    // initialise graph object
    int vertices = 3; 
    graph* g;
    g = (graph *) malloc(sizeof *g);
    bool directed = true;
    initialize_graph(g, directed); 
    read_graph(g, directed);

    // print the adjacency list representation of the above graph 
    print_graph(g); 
    prim(g, 1);

    return 0;
}