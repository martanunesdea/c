/* 
 *      Title:  Floyd's  algorithm
 *    Section:  All-pairs shortest path
 *    Summary:  Implementing a solution for shortest path
 *     Author:  Marta Nunes de Abreu
 *       Date:  04/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef struct {
    int weight[MAX+1][MAX+1];
    int n_vertices;
} adjacency_matrix;

void floy(adjacency_matrix *g)
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