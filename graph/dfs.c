//
// Created by dmitry on 24.02.2020.
//

#define WHITE 'w'
#define GRAY 'g'
#define BLACK 'b'

int search_array[GRAPH_SIZE];
char color[GRAPH_SIZE];

void dfs_visit(Graph *g, Edge *u) {
    if(u == NULL)
        return;
    color[u->x] = GRAY;
    Edge *p = u;
    while(p != NULL)
    {
        if(color[p->y] == WHITE)
        {
            search_array[p->x] = p->y;
            dfs_visit(g, g->edges[p->y]);
        }

        p = p->next;

    }
    color[u->x] = BLACK;
}


void dfs(Graph *g, int s) {

    for (int i = 0; i < GRAPH_SIZE; ++i) {
        bool vertex = g->vertices[i];
        if (vertex) {
            search_array[i] = -1;
            color[i] = WHITE;
        }
    }
    dfs_visit(g, g->edges[s]);
}

