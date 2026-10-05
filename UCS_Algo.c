#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int visited[MAX];
int distance[MAX];
int parent[MAX];

void UCS(int vertices, int start, int goal)
{
    int i, j;
    int current, minCost;

    for (i = 0; i < vertices; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[start] = 0;

    for (i = 0; i < vertices; i++)
    {
        current = -1;
        minCost = INF;

        /* Find unvisited vertex with minimum cost */
        for (j = 0; j < vertices; j++)
        {
            if (!visited[j] && distance[j] < minCost)
            {
                minCost = distance[j];
                current = j;
            }
        }

        if (current == -1)
            break;

        visited[current] = 1;

        /* Goal reached */
        if (current == goal)
            break;

        /* Update adjacent vertices */
        for (j = 0; j < vertices; j++)
        {
            if (graph[current][j] != 0 && !visited[j])
            {
                int newCost = distance[current] + graph[current][j];

                if (newCost < distance[j])
                {
                    distance[j] = newCost;
                    parent[j] = current;
                }
            }
        }
    }

    if (distance[goal] == INF)
    {
        printf("No path exists.\n");
        return;
    }

    printf("\nMinimum Cost: %d\n", distance[goal]);
    printf("Path: ");

    int path[MAX];
    int count = 0;
    int vertex = goal;

    while (vertex != -1)
    {
        path[count++] = vertex;
        vertex = parent[vertex];
    }

    for (i = count - 1; i >= 0; i--)
    {
        printf("%d", path[i]);

        if (i != 0)
            printf(" -> ");
    }

    printf("\n");
}

int main()
{
    int vertices, edges;
    int u, v, cost;
    int start, goal;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Initialize graph */
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v cost):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &cost);
        graph[u][v] = cost;
        graph[v][u] = cost;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("Enter goal vertex: ");
    scanf("%d", &goal);
    UCS(vertices, start, goal);
    printf("Samriddhi Gautam : BIT28 :LabI3");
    return 0;
}
