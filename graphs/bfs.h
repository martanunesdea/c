/* 
 *      Title:  Header of Breadth First Search
 *    Section:  Graphs
 *    Summary:  Implementing BFS with unweighted graphs
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include "graphs.h"

void initialize_search(struct graph *g);
void process_vertex_late( int v );
void process_vertex_early(int v);
void process_edge(int x, int y);
void connected_components(struct graph *g);
void process_vertex_early(int v);
void process_edge(int x, int y);
void bfs(struct graph *g, int start);