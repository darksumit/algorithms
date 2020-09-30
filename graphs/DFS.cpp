#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int s, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V=V;
    adj= new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int s, bool visited[])
{
    visited[s]=true;
    cout<<s<<"  ";

    list<int>::iterator i;

    for(i=adj[s].begin(); i!=adj[s].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int s)
{
    bool *visited= new bool[V];

    for(int i=0;i<V;i++)
        visited[i]=false;

    DFSUtil(s, visited);
}

int main()
{
    Graph G(6);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 4);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(4, 5);
    cout<<"DFS of the Graph is: \n";
    G.DFS(0);
    cout<<"\n";
    return 0;
}
