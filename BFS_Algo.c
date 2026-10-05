#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

void BFS(int start, int vertices)
{
    int front = 0, rear = 0;
    int current, i;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
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

    BFS(start, vertices);
    printf("Samriddhi Gautam : BIT28 : LabI1");
    return 0;
}
