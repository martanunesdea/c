/* 
 *      Title:  Header for Depth-first-based source code
 *    Section:  Graphs
 *    Summary:  Implementing depth first-based trasversal
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "graphs.h"

void process_edge(int x, int y);
void process_vertex_late( int v );
void process_vertex_early(int v);
void dfs(struct graph *g, int v);