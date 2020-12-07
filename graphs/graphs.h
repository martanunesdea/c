/* 
 *      Title:  Header for Graphs
 *    Section:  Graphs
 *    Summary:  Header of directional, non-directional and weighted adjacency lists
 *     Author:  Marta Nunes de Abreu
 *       Date:  05/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#ifndef GRAPHS_H
#define GRAPHS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV        1000

typedef struct {
    int y;                      /* adjacency info */
    int weight;                 /* edge weight, if any */
    struct edgenode *next;      /* next edge in list */
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];    /* adjacency info */
    int degree[MAXV+1];         /* outdegree of each vertex */
    int nvertices;              /* number of vertices in graph */
    int nedges;                 /* number of edges in graph */
    bool directed;              /* is the graph directed? */
} graph;

void initialize_graph(graph *g, bool directed);
void insert_edge(graph *g, int x, int y, bool directed, int weight);
void read_graph(graph *g, bool directed);
void print_graph(graph *g);

#endif