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
#include "queue.h"
#include "graphs.h"

bool finished = 0;
/* DFS organises vertices by entry/exit times,
 * and edgs into tree and back edges. */
int entry_time[MAX+1];    /* time we started discovering node */
int exit_time[MAX+1];     /* time we finished discovering one node */
int time = 0;             /* global time instance */

/* this cycle detection depends on
 * processing each undirected edge exactly once. 
 * Other wise a spurious tw-vertex cycle 
 * could be composed from 2 traversals of any single undirected edge */ 
void process_edge(int x, int y)
{
    if (parent[x] != y)
    {
        printf("Cyclefrom %d to %d: ", y, x);
        printf("\n\n");
        // find_path(y, x, parent);
        finished = TRUE; // use this flag to terminate after finding the cycle
    }
}
/* through the processs functions, can customize what the traversal does 
 * as it makes its official visit to each edge and each vertex */
void process_vertex_late( int v )
{
    // returns without action, since all processing done early on
}

void process_vertex_early(int v)
{
    printf("1. Discovering vertex %d \n", v);
}

void dfs(struct graph *g, int v)
{
    struct adj_node *p;    /* temporary pointer */
    int y;          /* successor vertex */

    if (finished)
    {
        return;
    }

    discovered[v] = TRUE;
    time += 1;
    entry_time[v] = time;

    process_vertex_early(v);

    p = g->array[v].head;

    while (p != NULL)
    {
        y = (p->next)->dest;
        if ( discovered[y] == FALSE )
        {
            parent[y] = v;
            process_edge(v, y);
            dfs(g, y);
        }
        else if( (!processed[y]) )
        {
            process_edge(v, y);
        }
        if (finished)
        {
            return;
        }
        if( p->next != NULL)
        {
            p = p->next;
        }
        else
        {
            break;
        }
        

    }
    process_vertex_late(v);
    time += 1;
    exit_time[v] = time;
    processed[v] = TRUE;
}




int main(void)
{
    struct graph *g;
    g = (struct graph*) malloc(sizeof *g);

    // initialise graph object
    int vertices = 5; 
    g = graph_initialize(vertices); 
    
    graph_insert_edge(g, 0, 1);
    graph_insert_edge(g, 0, 4);
    graph_insert_edge(g, 1, 2);
    graph_insert_edge(g, 1, 4);

    // print the adjacency list representation of the above graph 
    graph_print(g);

    printf("\n\n Depth first search: \n ");
    dfs(g, 0);
    return 0;
}