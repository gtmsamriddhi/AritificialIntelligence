#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int heuristic[MAX];
int visited[MAX];
int path[MAX];
int pathIndex = 0;

void hillClimbing(int current, int goal, int vertices)
{
    int i;
    int next = -1;
    int bestHeuristic;

    visited[current] = 1;
    path[pathIndex++] = current;

    printf("%d ", current);

    /* Goal reached */
    if (current == goal)
        return;

    bestHeuristic = heuristic[current];

    /* Find the best neighboring vertex */
    for (i = 0; i < vertices; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
        {
            if (heuristic[i] < bestHeuristic)
            {
                bestHeuristic = heuristic[i];
                next = i;
            }
        }
    }

    /* No better neighbor found */
    if (next == -1)
        return;

    /* Move to the better neighbor */
    hillClimbing(next, goal, vertices);
}

int main()
{
    int vertices, edges;
    int u, v;
    int start, goal;
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

        /* Undirected graph */
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter heuristic values:\n");

    for (i = 0; i < vertices; i++)
    {
        printf("h(%d) = ", i);
        scanf("%d", &heuristic[i]);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("Enter goal vertex: ");
    scanf("%d", &goal);

    printf("\nHill Climbing Path: ");
    hillClimbing(start, goal, vertices);

    if (path[pathIndex - 1] == goal)
        printf("\nGoal reached.\n");
    else
        printf("\nGoal could not be reached. Local maximum reached.\n");
        printf("Samriddhi Gautam : BIT28 : LabI6");
    return 0;
}
