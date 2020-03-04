//
// Created by dmitry on 04.03.2020.
//


#include "limits.h"


int getNearestUnvisited(Graph *g, const int *dist, const bool *visited) {
    int min = INT_MAX;
    int minVertex = -1;
    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (g->vertices[i]) {
            if (dist[i] < min && visited[i] == false) {
                min = dist[i];
                minVertex = i;
            }
        }
    }
    return minVertex;
}


void dijkstra(Graph *g, int s) {
    int dist[GRAPH_SIZE];
    int pred[GRAPH_SIZE];
    bool visited[GRAPH_SIZE];
    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (g->vertices[i]) {
            dist[i] = INT_MAX;
            dist[i] = -1;
            visited[i] = false;
        }
    }
    dist[s] = 0;
    int u = getNearestUnvisited(g, dist, visited);
    while (u != -1) {
        if(dist[u] == INT_MAX)
            return;
        visited[u] = true;
        Edge *p = g->edges[u];
        while(p != NULL)
        {
            int w = p->weight;
            int v = p->y;
            int newDist = dist[u] + w;
            if(newDist < dist[v])
                dist[v] = newDist;
            pred[v] = u;
            p = p->next;
        }
        u = getNearestUnvisited(g, dist, visited);
    }
}
