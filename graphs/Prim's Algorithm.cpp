#include <stdio.h>
#include <limits.h>

#define V 5

int minimum(int key[], bool visited[])
{
    int min=INT_MAX, index;
    for(int i=0; i<V; i++)
        if(!visited[i] && key[i]<min)
            index=i, min=key[i];
    return index;
}

int display(int parent[], int graph[V][V])
{
    printf("Edge\tWeight\n");
    for(int i=1; i<V; i++)
        printf("%d-->%d\t  %d\n",parent[i],i,graph[i][parent[i]]);
}

void Prim(int graph[V][V])
{
    int parent[V], key[V];
    bool visited[V];

    for(int i=0; i<V; i++)
        key[i]=INT_MAX, visited[i]=false;

    key[0]=0, parent[0]=-1;
    for(int i=0; i<V-1; i++)
    {
        int u=minimum(key, visited);
        visited[u]=true;

        for(int v=0; v<V; v++)
            if(graph[u][v] && !visited[v] && graph[u][v]<key[v])
                parent[v]=u, key[v]=graph[u][v];
    }
    display(parent, graph);
}

int main()
{
    int graph[V][V]={{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}};
    Prim(graph);
    return 0;
}
