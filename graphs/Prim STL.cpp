#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> Pair;

class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<Pair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST()
{
    priority_queue< Pair, vector <Pair> , greater<Pair> > pq;

    int src = 0;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
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

    G.primMST();
    return 0;
}
