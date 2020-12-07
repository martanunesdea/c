/* 
 *      Title:  Graphs
 *    Section:  Graphs
 *    Summary:  Directional, non-directional and weighted adjacency lists
 *     Author:  Marta Nunes de Abreu
 *       Date:  05/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "graphs.h"

void initialize_graph(graph *g, bool directed)
{
    int i;

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    if ( directed == true) 
    {
        printf("making a directed graph \n");
    }

    for (i = 1; i <= MAXV; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed, int weight)
{
    edgenode *p;
    printf("Inserting edge between: (%d, %d)\n", x, y);
    p = (edgenode *) malloc(sizeof(*p));
    p->y = y;
    p->next = (struct edgenode *) g->edges[x];
    if ( weight > 0 )
    {
        p->weight = weight;
    }
    else {
        p->weight = -1;
    }

    g->edges[x] = p;
    g->degree[x] += 1;

    if ( directed == false )
    {
        insert_edge(g, y, x, true, weight);
    }
    else
    {
        g->nedges += 1;
    }

}

void read_graph(graph *g, bool directed)
{
    int i;
    int m;
    int x, y;
    int w;          /* for weight */

    initialize_graph(g, directed);

    scanf("%d %d", &(g->nvertices), &m);
    printf("Number of vertices: %d \n Number of edges: %d \n\n", g->nvertices, m);

    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        insert_edge(g, x, y, directed, w);
    }
}


void print_graph(graph *g)
{
    int i;
    edgenode *p;

    for ( i = 1; i <= g->nvertices; i++)
    {
        printf("%d: ", i);
        p = g->edges[i];
        while ( p != NULL )
        {
            printf(" %d", p->y);
            p = (edgenode*) p->next;
        }
        printf("\n");
    }
}



int test_graph(void)
{
    graph *g1;
    g1 = (graph *) malloc(sizeof *g1);
    bool directed = false;
    printf("\n\n Reading in graph elements: \n");
    initialize_graph(g1, directed);
    read_graph(g1, directed);

    printf("\n\n Printing graph \n");
    print_graph(g1);

    return 0;
}