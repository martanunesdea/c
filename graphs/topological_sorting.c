/* 
 *      Title:  Topological sorting
 *    Section:  Graphs
 *    Summary:  Sorting weighted graphs
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "graphs.h"
#include "traversal.h"

struct stack *sorted;

#define ERROR (-1)
#define TREE 1
#define BACK 2
#define FORWARD 3
#define CROSS 4

int edge_classification(int x, int y)
{
    if( parent[y] == x)
        return(TREE);
    if ( discovered[y] && !processed[y] )
        return(BACK);
    if ( processed[y] && (entry_time[y] > entry_time[x]) )
        return(FORWARD);
    if ( processed[y] && (entry_time[y] < entry_time[x]) )
        return(CROSS);
    else
    {
        printf("Warning: Unclassified edge (%d, %d)\n", x, y);
        return ERROR;
    }    
}

void process_vertex_late(int v)
{
    push(&sorted, v);
}

void process_edge(int x, int y)
{
    int class;  /* edge class */
    class = edge_classification(x, y);
    
    if ( class == BACK )
    {
        printf("Warning: directed cycle found, not a DAG.\n");
    }
}

void topsort(graph *g)
{
    int i; /* counter */
    stack_initialize(&sorted);
    
    for ( i = 1; i <= g->nvertices; i++)
    {
        if ( discovered[i] == false )
        {
            dfs(g, i);
        }
    }
    print_stack(&sorted);   /* report topological order */
}