#include <stdio.h>
#include "graph/graph.h"
int main() {
    Graph *g = malloc(sizeof(Graph));
    for (int i = 0; i < GRAPH_SIZE; ++i) {
        g->edges[i] = NULL;
        g->vertices[i] = 0;
    }
    graph_add_edge(g, 1, 2, 1);
    graph_add_edge(g, 2, 3, 10);
    graph_add_edge(g, 1, 3, 2);
    printf("%d->%d: %d\n", 1, 2, g->edges[1]->next->weight);
    printf("%d->%d: %d\n", 2, 3, g->edges[2]->weight);
    printf("%d->%d: %d\n", 1, 3, g->edges[1]->weight);

    dfs(g, 1);

    for (int j = 0; j < GRAPH_SIZE; ++j) {
        int y = search_array[j];
        if(y > 0)
        {
            printf("%d -> %d\n", j, y);
        }
    }

    return 0;
}
