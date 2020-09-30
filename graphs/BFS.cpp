#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int vertex;
    list<int> *adj;
public:
    Graph(int item);
    void addedge(int v, int w);
    void BFS(int val);
};

Graph :: Graph(int item)
{
    this->vertex = item;
    adj = new list<int>[item];
}

void Graph :: addedge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph :: BFS(int val)
{
    bool *visited = new bool[vertex];
    for (int i=0; i<vertex; i++)
        visited[i] = 0;

    list<int> queue;
    visited[val] = true;
    queue.push_back(val);

    list<int> :: iterator i;

    while(!queue.empty())
    {
        val = queue.front();
        cout << val << '\t';
        queue.pop_front();

        for(i=adj[val].begin(); i!=adj[val].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph G(4);
    G.addedge(0, 1);
    G.addedge(0, 2);
    G.addedge(1, 2);
    G.addedge(2, 0);
    G.addedge(2, 3);
    G.addedge(3, 3);

    cout << "BFS Traversal from Vertex 2:" << endl;
    G.BFS(2);
    cout << endl;

    return 0;
}
