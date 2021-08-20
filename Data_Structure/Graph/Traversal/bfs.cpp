/* 
Traversal of the Graph :BFS( Breadth First Search)
Time complexity: O(V+E) if it is a adj_list graph repreasentation else O(V*V)
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graph
{
    int V;                   // for storing the number of vertex
    int E;                   // for number of edges
    vector<vector<int>> adj; // for vector of list storage
    vector<int> value;       // to store the value associated with the node of the graph

    // constructor
    Graph(int v, int e)
    {
        V = v;
        E = e;
        adj.resize(V + 1); // make it size of V+1 to support the 1-based indexing too
        value.assign(V + 1, 0);
    }

    // add edge O(1) time complexity
    void add_edge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // remove edge : time complexity: O(V);
    void remove_edge(int x, int y)
    {
        for (auto it = adj[x].begin(); it != adj[x].end(); it++)
        {
            if (*it == y)
            {
                adj[x].erase(it);
                break;
            }
        }
        for (auto it = adj[y].begin(); it != adj[y].end(); it++)
        {
            if (*it == x)
            {
                adj[y].erase(it);
                break;
            }
        }
    }

    // print graph
    void print()
    {
        int i = 0;
        for (auto it : adj)
        {
            cout << i << ": ";
            for (auto jt : it)
                cout << jt << " ";
            cout << endl;
            i++;
        }
    }
};

void explore(Graph *G, vector<bool> &visited, int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (q.empty() != true)
    {
        int v;
        v = q.front();
        cout << v << " ";
        q.pop();
        for (auto it : G->adj[v])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
void bfs(Graph *G, int s)
{
    int v = G->V;
    vector<bool> visited(v + 1, false); // to store the which all nodes have been visited
    int count = 0;                      // count the number of disconnected component in the graph
    explore(G, visited, s);
    count=1;
    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == false)
        {
            count++;
            explore(G, visited, i);
        }
    }
}
int main()
{
    Graph *G = new Graph(6, 5);
    G->add_edge(1, 2);
    G->add_edge(1, 3);
    G->add_edge(3, 4);
    G->add_edge(2, 4);
    G->add_edge(6, 5);
    G->remove_edge(1, 3);
    G->print();
    cout << "bfs is: ";
    bfs(G, 2);
    cout << endl;
    return 0;
}
