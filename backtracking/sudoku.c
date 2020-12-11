/* 
 *      Title:  Backtracking 
 *    Section:  Backtracking
 *    Summary:  Iterating through possible configurations of a given search spacexs
 *     Author:  Marta Nunes de Abreu
 *       Date:  11/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "backtracking.h"

#define DIMENSION   9
#define NCELLS      DIMENSION*DIMENSION

typedef struct {
    int x, y;
} point;

typedef struct {
    int m[DIMENSION+1][DIMENSION+1];
} boardtype;

typedef struct {
    int m[DIMENSION+1][DIMENSION+1];    /* matrix of board contents */
    int freecount;                      /* open squares remaining */
    point move[NCELLS+1];
}

/* Constructing the candidates for next solution pos. involves: 
 * 1. picking the open square to fill (next_square)
 * 2. identifying which numbers are candidates (possible_values) 
 */
void construct_candidates(int a[], int k, boardtype *board, int c[], int *ncandidates)
{
    int x, y;       /* position of next move */
    int i;          /* counter */
    bool possible[DIMENSION+1];

    next_square(&x, &y, board);

    board->move[k].x = x;
    board->move[k].y = y;

    *ncandidates = 0;

    if ( (x<0) && (y<0) ) 
        return; /*error, no moves possible */

    possible_values(x, y, board, possible);
    for ( i = 0; i <= DIMENSION; i++ )
    {
        if ( possible[i] == TRUE )
        {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}


void make_move(int a[],int k, boardtype *board)
{
    fill_square(board->move[k].x, board->move[k].y, a[k], board);
}

void unmake_move(int a[], int k, boardtype *board)
{
    free_square(board->move[k].x, board->move[k].y, board);
}

int is_a_solution(int a[], int k, boardtype *board)
{
    if (board->freecount == 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
    
}

void process_solution(int a[], int k, boardtype *board)
{
    print_board(board);
    finished = true;
}