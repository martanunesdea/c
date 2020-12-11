/* 
 *      Title:  All permutations
 *    Section:  Backtracking
 *    Summary:  Constructing all permutations
 *     Author:  Marta Nunes de Abreu
 *       Date:  11/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "backtracking.h"
#define NMAX 10


void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
    int i;                  /* counter */
    bool in_perm[NMAX];     /* who is in the permutation */

    for ( i = 1; i < NMAX; i++ )
        in_perm[i] = false;
    
    for ( i = 0; i < k; i++ )
        in_perm[ a[i] ] = true;
    
    *ncandidates = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( in_perm[i] == false )
        {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }

}

void process_solution(int a[], int k)
{
    int i;

    for ( i = 1; i <= k; i++ )
    {
        printf(" %d", a[i]);
    }
    printf("\n");

}

is_a_solution(int a[], int k, int n)
{
    return ( k == n);
}

generate_permutations(int n)
{
    int a[NMAX];    /* solution vector */ 

    backtrack(a, 0, n);
}