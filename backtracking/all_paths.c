/* 
 *      Title:  All paths in a graph
 *    Section:  Backtracking
 *    Summary:  Constructing all paths in a graph
 *     Author:  Marta Nunes de Abreu
 *       Date:  11/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "backtracking.h"
#include "graphs.h"
#define NMAX 10

int solution_count = 0;
graph g;

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
    int i;              /* counters */
    bool in_sol[NMAX];  /* what's in the solution already */
    edgenode *p;        /* temporary pointer */
    int last;           /* last vertex on current path */

    for ( i = 1; i < NMAX; i++ )
    {
        in_sol[i] = false;
    }
    for ( i = 1; i < k; i++)
    {
        in_sol[ a[i] ] = true;
    }
    if ( k == 1 )
    {
        c[0] = 1;
        *ncandidates = 1;
    }
    else {
        *ncandidates = 0;
        last = a[k-1];
        p = g.edges[last];
        while ( p != NULL)
        {
            if ( !in_sol[ p->y ] ) {
                c[*ncandidates] = p->y;
                *ncandidates = *ncandidates + 1;
            }
            p = p->next;
        }
    }

}

int is_a_solution(int a[], int k, int t)
{
    return ( a[k] == t );
}

void process_solutin(int a[], int k)
{
    solution_count++;
}

void generate_paths(void )
{
    // initiate backtracking
}