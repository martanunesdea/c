/* 
 *      Title:  Dijkstra's  algorithm
 *    Section:  Shortest Path in Weighted Graphs
 *    Summary:  Implementing a solution for shortest path
 *     Author:  Marta Nunes de Abreu
 *       Date:  03/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>

void dijkstra(graph *g, int start)
{
    int i;
    struct adj_node *p;
    bool intree[MAX+1];
    int distance[MAX+1];

    int v;
    int w;
    int weight;
    int dist;

    for (int i = 1; i <= g->n_vertices; i++)
    {
        intree[i] = FALSE;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;

    while (intree[v] == FALSE)
    {
        intree[v] = TRUE;
        p = g->array[v].head;
        while( p!= NULL) 
        {
            w = p->y;
            weight = p->weight;
            if (distance[w] > (distance[v]+weight))
            {
                distance[w] = distance[v]+weight;
                parent[w] = v;
            }
            p = p->next;
        }
        v = 1;
        dist = MAXINT;
        for(i = 1; i <= g->n_vertices; i++)
        {
            if ( (intree[i] == FALSE) && 
                (dist > distance[i]) )
                {
                    dist = distance[i];
                    v = i;
                }
        }
    }
}

int main( void )
{
    return 0;
}