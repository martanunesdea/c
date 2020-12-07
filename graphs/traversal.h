/* 
 *      Title:  Header of Traversal
 *    Section:  Graphs
 *    Summary:  Header for implementing BFS, DFS and some applications
 *     Author:  Marta Nunes de Abreu
 *       Date:  05/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <stdbool.h>
#include "graphs.h"
#include "queue.h"

/* for BFS */
bool processed[MAXV+1];     /* which vertices have been processed */ 
bool discovered[MAXV+1];    /* which vertices have been found */
int parent[MAXV+1];         /* discovery relation */
int nedges;

/* for DFS */
static bool finished = false;
/* DFS organises vertices by entry/exit times,
 * and edgs into tree and back edges. */
int entry_time[MAXV+1];    /* time we started discovering node */
int exit_time[MAXV+1];     /* time we finished discovering one node */
static int time = 0;  


void initialize_search(graph *g);
void process_vertex_early( int v);
void process_edge(int x, int y);
void process_vertex_late( int v );
void bfs(graph *g, int start);
void find_path(int start, int end, int parents[]);
void connected_components( graph *g );
void dfs_process_edge(int x, int y);
void dfs_process_vertex_early( int v);
void dfs_process_vertex_late( int v );
void dfs( graph *g, int v);

#endif