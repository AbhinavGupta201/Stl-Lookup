/*
 Adjcency List 
Space complexity: O(V+E)
Author: Abhinav Gupta
 */
#include <iostream>
#include <vector>
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

int main()
{
    Graph *G = new Graph(4, 5);
    G->add_edge(1, 2);
    G->add_edge(1, 3);
    G->add_edge(1, 4);
    G->add_edge(3, 4);
    G->add_edge(2, 4);
    G->print();
    G->remove_edge(1, 4);
    return 0;
}