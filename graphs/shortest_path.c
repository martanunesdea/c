/* 
 *      Title:  Shortest Path
 *    Section:  Graphs
 *    Summary:  Implementing algorithms for shortest path
 *     Author:  Marta Nunes de Abreu
 *       Date:  03/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graphs.h"

#define MAXINT 100

typedef struct {
    int weight[MAXV+1][MAXV+1];
    int n_vertices;
} adjacency_matrix;

void floyd(adjacency_matrix *g)
{
    int i, j;
    int k;
    int through_k;

    for (k = 1; k <= g->n_vertices; k++)
    {
        for(i = 1; i <= g->n_vertices; i++)
        {
            for (j = 1; j <= g->n_vertices; j++)
            {
                through_k = g->weight[i][k] + g->weight[k][j];
                if ( through_k < g->weight[i][j] )
                { 
                    g->weight[i][j] = through_k;
                }
            }
        }
    }
}

void dijkstra(graph *g, int start)
{
    int i;
    edgenode *p;
    bool intree[MAXV+1];
    int distance[MAXV+1];
    int parent[MAXV+1];

    int v;
    int w;
    int weight;
    int dist;

    for (int i = 1; i <= g->nvertices; i++)
    {
        intree[i] = false;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        p = g->edges[v];
        while(p != NULL) 
        {
            w = p->y;
            weight = p->weight;
            if (distance[w] > (distance[v]+weight))
            {
                distance[w] = distance[v]+weight;
                parent[w] = v;
            }
            p = (edgenode *) p->next;
        }
        v = 1;
        dist = MAXINT;
        for(i = 1; i <= g->nvertices; i++)
        {
            if ( (intree[i] == false) && 
                (dist > distance[i]) )
                {
                    dist = distance[i];
                    v = i;
                }
        }
    }

    printf("\n\n ---- shortest path \n\n");
    for( int j = 1; j <= g->nvertices; j++)
    {
        printf(" %d ", parent[j]);
    }
}

int main( void )
{
    graph* g;
    g = (graph *) malloc(sizeof *g);
    bool directed = true;
    initialize_graph(g, directed); 
    read_graph(g, directed);

    // print the adjacency list representation of the above graph 
    print_graph(g); 
    dijkstra(g, 1);


    return 0;
}