#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int path[MAX];
int pathIndex = 0;

int DLS(int current, int goal, int depth, int vertices)
{
    int i;

    visited[current] = 1;
    path[pathIndex++] = current;

    if (current == goal)
        return 1;

    if (depth == 0)
    {
        pathIndex--;
        return 0;
    }

  
    for (i = 0; i < vertices; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
        {
            if (DLS(i, goal, depth - 1, vertices))
                return 1;
        }
    }

    pathIndex--;
    return 0;
}

int main()
{
    int vertices, edges;
    int u, v;
    int start, goal, limit;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Initialize graph */
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

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    printf("Enter depth limit: ");
    scanf("%d", &limit);

    if (DLS(start, goal, limit, vertices))
    {
        printf("\nGoal found!\n");
        printf("Path: ");

        for (i = 0; i < pathIndex; i++)
        {
            printf("%d", path[i]);

            if (i < pathIndex - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nGoal not found within the given depth limit.\n");
    }
    return 0;
}
