#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

class Graph
{
    int V;
    list< pair<int,int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int source)
{
    set< pair<int, int> > setds;
    vector<int> dist(V, INF);

    setds.insert(make_pair(0, source));
    dist[source] = 0;

    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int V = 9;
    Graph G(V);

    G.addEdge(0, 1, 4);
    G.addEdge(0, 7, 8);
    G.addEdge(1, 2, 8);
    G.addEdge(1, 7, 11);
    G.addEdge(2, 3, 7);
    G.addEdge(2, 8, 2);
    G.addEdge(2, 5, 4);
    G.addEdge(3, 4, 9);
    G.addEdge(3, 5, 14);
    G.addEdge(4, 5, 10);
    G.addEdge(5, 6, 2);
    G.addEdge(6, 7, 1);
    G.addEdge(6, 8, 6);
    G.addEdge(7, 8, 7);

    G.shortestPath(0);
    return 0;
}
