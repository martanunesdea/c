
/* 
 *      Title:  Header for Union find
 *    Section:  Graphs
 *    Summary:  Header for finding membership in a set
 *     Author:  Marta Nunes de Abreu
 *       Date:  02/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define SET_SIZE 100

typedef struct {
    int parent[SET_SIZE+1]; // parent element
    int size[SET_SIZE+1];   // number of elements in subtree i
    int n;                  // number of elements in set
} set_union;


void set_union_initialize(set_union *s, int n);
int find(set_union *s, int x);
void union_sets(set_union *s, int s1, int s2);
bool same_component(set_union *s, int s1, int s2);
int set_union_test(void);

#endif