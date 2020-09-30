#include <stdio.h>
#include <limits.h>

#define V 9

int minimum(int dist[], bool visited[])
{
    int min=INT_MAX, index;
    for(int i=0; i<V; i++)
        if(!visited[i] && dist[i]<min)
            index=i, min=dist[i];
    return index;
}

void display(int dist[])
{
    printf("Edge\tWeight\n");
    for(int i=1; i<V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int Dijkstra(int graph[V][V], int source)
{
    int dist[V];
    bool visited[V];

    for(int i=0; i<V; i++)
        dist[i]=INT_MAX, visited[i]=false;

    dist[source]=0;
    for(int i=0; i<V-1; i++)
    {
        int u=minimum(dist, visited);
        visited[u]=true;

        for(int v=0; v<V; v++)
            if(graph[u][v] && !visited[v] && dist[u]+graph[u][v]<dist[v] && dist[u]<INT_MAX)
                dist[v]=dist[u]+graph[u][v];
    }
    display(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    Dijkstra(graph, 0);
    return 0;
}
