/* 
 *      Title:  Backtracking 
 *    Section:  Backtracking
 *    Summary:  Iterating through possible configurations of a given search spacexs
 *     Author:  Marta Nunes de Abreu
 *       Date:  10/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCANDIDATES 5

bool finished = false; /* flag all solutions are found */

int is_a_solution(int a[], int k, int n)
{
    return (k == n); /* true if we've got solution */
}

void process_solution(int a[], int k, int n)
{
    int i;

    printf("{");
    for ( i = 1; i <= k; i++ )
    {
        if ( a[i] == true )
            printf(" %d", i);
    }
    printf("}");
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void backtrack(int a[],int k, int input)
{
    int c[MAXCANDIDATES];   /* candidates for next position */
    int ncandidates;        /* next position candidate count */
    int i;

    if ( is_a_solution(a, k, input) )
        process_solution(a, k, input);
    else {
        k = k+1;
        construct_candidates(a, k, input, c, &ncandidates);
        for ( i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            make_move(a, k, input);
            backtrack(a, k, input);
            unmake_move(a, k, input);
            if ( finished )
                return; /* terminate early */
        }  
    }
}