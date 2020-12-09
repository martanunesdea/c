/* 
 *      Title:  Network Flows
 *    Section:  Graphs
 *    Summary:  Studying relations of graphs through flows
 *     Author:  Marta Nunes de Abreu
 *       Date:  02/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"
#include "traversal.h"
#include "union_find.h"
#define MAXINT 1000

typedef struct {
    int v;                      /* neighbouring vertex */
    int capacity;               /* capacity of edge */
    int flow;                   /* flow through edge */
    int residual;               /* residual capacity of edge */
    struct edgenode *next;      /* next edge in list */ 
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
} flow_graph;

/* only consider edges that have remaining capacity, or positive residual flow 
 * help bfs distinguish between saturated and unsaturated edges */
bool valid_edge(edgenode *e)
{
    if ( e->residual > 0 )
        return true;
    else
        return false;    
}

edgenode *find_edge(flow_graph *g, int x, int y)
{
    edgenode *p;
    p = g->edges[x];

    while ( p != NULL )
    {
        if ( p->v == y)
            return(p);
        p = p->next;
    }
}

/* The act of augmenting a path requires modifying
 * both forward and reverse edges for each link on the path */
void augment_path(flow_graph *g, int start, int end, int parents[], int volume)
{
    edgenode *e;
    edgenode *find_edge();

    if ( start == end )
        return;

    e = find_edge(g, parents[end], end);
    e->flow += volume;
    e->residual -= volume;

    e = find_edge(g, end, parents[end]);
    e->residual += volume;

    augment_path(g, start, parents[end], parents, volume);
}


int path_volume(flow_graph *g, int start, int end, int parents[])
{
    edgenode *e;            /* edge in question */
    edgenode *find_edge();

    if ( parents[end] == -1 )
        return(0);
    
    e = find_edge(g, parents[end], end);

    if (start == parents[end])
        return(e->residual);
    else
        return( min(path_volume(g, start, parents[end], parents), e->residual) );
    
}
/* use BFS to look for a path from source to sink,
   that increases the total flow, 
   and use it to augment the total */
void netflow(flow_graph *g, int source, int sink)
{
    int volume;     /* weight of the augmenting path */

    add_residual_edges(g);

    initialize_search(g);
    bfs(g, source);

    volume = path_volume(g, source, sink, parent);

    /* terminate the optimal flow when no augmenting path exists */
    while ( volume > 0 )
    {
        augment_path(g, source, sink, parent, volume);
        initialize_search(g);
        bfs(g, source);
        volume = path_volume(g, source, sink, parent);
    }

}