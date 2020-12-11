/* 
 *      Title:  Header for Backtracking 
 *    Section:  Backtracking
 *    Summary:  Iterating through possible configurations of a given search spacexs
 *     Author:  Marta Nunes de Abreu
 *       Date:  10/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#define MAXCANDIDATES 5

int is_a_solution(int a[], int k, int n);
void process_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void backtrack(int a[],int k, int input);