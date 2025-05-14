#include <stdio.h>
#include <limits.h>

#define V 5

// find the vertex with minimum distance value
int minDistance(int dist[], int sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    }

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{

    int dist[V];   // Output array
    int sptSet[V]; // sptSet is true if vertex set is included in the tree

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count <= V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}};

    int source = 0;
    dijkstra(graph, source);

    return 0;
}