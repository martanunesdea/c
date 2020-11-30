/* 
 *      Title:  Depth-first-based
 *    Section:  Graphs
 *    Summary:  Implementing adjacency lists
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool finished = 0;

/* DFS organises vertices by entry/exit times,
 * and edgs into tree and back edges. */

void dfs(graph *g, int v)
{
    edgenode *p;    /* temporary pointer */
    int y;          /* successor vertex */

    if (finished)
    {
        return;
    }

    discovered[v] = TRUE;
    time += 1;
    entry_time[v] = time;

    process_vertex_early(v);

    p = g->edges[v];

    while (p != NULL)
    {
        y = p->y;
        if ( discovered[y] == FALSE )
        {
            parent[y] = v;
            process_edge(v, y);
            dfs(g, y);
        }
        else if( (!processed[y]) || (g->directed) )
        {
            process_edge(v, y);

        }
        if (finished)
        {
            return;
        }
        p = p->next;
    }
    process_vertex_late(v);
    time += 1;
    exit_time(v) = time;
    processed[v] = TRUE;
}


/* this cycle detection depends on
 * processing each undirected edge exactly once. 
 * Other wise a spurious tw-vertex cycle 
 * could be composed from 2 traversals of any single undirected edge */ 
process_edge(int x, int y)
{
    if (parent[x] != y)
    {
        printf("Cyclefrom %d to %d: ", y, x);
        printf("\n\n");
        find_path(y, x, parent);
        finished = TRUE; // use this flag to terminate after finding the cycle
    }
}

int main(void)
{
    return 0;
}