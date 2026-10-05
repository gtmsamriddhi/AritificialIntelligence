#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFS(int vertex, int vertices)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i, vertices);
        }
    }
}

int main()
{
    int vertices, edges;
    int u, v, i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Initialize graph and visited array */
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;

        for (j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        /* Undirected graph */
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start, vertices);

    printf("\n");
    printf("Samriddhi Gautam: BIT28 :LabI2");
    return 0;
}
