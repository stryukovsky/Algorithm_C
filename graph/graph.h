//
// Created by dmitry on 24.02.2020.
//

#ifndef ALGORITHMS_C_GRAPH_H
#define ALGORITHMS_C_GRAPH_H

#include "stdlib.h"
#include "stdbool.h"


/*
 * This implementation of Graph is quite simple and uses edges instead of, for example, vectors*/

#define GRAPH_SIZE 100

typedef struct Edge{
    int x, y;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Graph{
    struct Edge* edges[GRAPH_SIZE];
    bool vertices[GRAPH_SIZE];
} Graph;

void graph_add_edge(Graph *g, int x, int y, int weight)
{
    Edge *p = malloc(sizeof(Edge));
    p->x = x;
    p->y = y;
    p->weight = weight;
    if(g->edges[x] != NULL)
    {
        p->next = g->edges[x];
    }
    g->edges[x] = p;
    g->vertices[x] = 1;
    g->vertices[y] = 1;

}
#include "dfs.c"
#include "bfs.c"
#include "dijkstra.c"

#endif //ALGORITHMS_C_GRAPH_H
