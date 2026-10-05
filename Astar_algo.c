#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int heuristic[MAX];
int g[MAX];
int f[MAX];
int parent[MAX];
int visited[MAX];

void AStar(int vertices, int start, int goal)
{
    int i, j;
    int current, minF;

    /* Initialize values */
    for (i = 0; i < vertices; i++)
    {
        g[i] = INF;
        f[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    g[start] = 0;
    f[start] = heuristic[start];

    while (1)
    {
        current = -1;
        minF = INF;

        /* Find vertex with minimum f value */
        for (i = 0; i < vertices; i++)
        {
            if (!visited[i] && f[i] < minF)
            {
                minF = f[i];
                current = i;
            }
        }

        /* No path exists */
        if (current == -1)
        {
            printf("\nNo path exists.\n");
            return;
        }

        /* Goal reached */
        if (current == goal)
            break;

        visited[current] = 1;

        /* Check adjacent vertices */
        for (j = 0; j < vertices; j++)
        {
            if (graph[current][j] != 0 && !visited[j])
            {
                int newG = g[current] + graph[current][j];

                if (newG < g[j])
                {
                    g[j] = newG;
                    f[j] = g[j] + heuristic[j];
                    parent[j] = current;
                }
            }
        }
    }

    /* Display result */
    printf("\nShortest Path: ");

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

    printf("\nTotal Cost: %d\n", g[goal]);
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

        /* Undirected weighted graph */
        graph[u][v] = cost;
        graph[v][u] = cost;
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

    AStar(vertices, start, goal);
    printf("Samriddhi Gautam : BIT28 :LabI5");
    return 0;
}
