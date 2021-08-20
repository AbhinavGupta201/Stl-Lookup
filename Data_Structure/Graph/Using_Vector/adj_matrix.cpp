/* 
Adj Matrix : 
Space Complexity: O(V*V)
Author : Abhinav Gupta
 */
#include <iostream>
#include <vector>
using namespace std;

struct Graph
{
    int V;                   // no of vertex;
    int E;                   // no of edges
    vector<int> value;       // for any value associated with the nodes
    vector<vector<int>> adj; // adj matrix

    Graph(int v, int e)
    {
        V = v;
        E = e;
        value.assign(V + 1, 0);
        adj.resize(V + 1, vector<int>(V + 1, 0));
    }

    void add_edge(int x, int y)
    {
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    void remove_edge(int x, int y)
    {
        adj[x][y] = 0;
        adj[y][x] = 0;
    }

    void print()
    {
        for (int i = 0; i < V + 1; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < V + 1; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"Value of the node:\n";
        for(int i=0;i<V+1;i++){
            cout<<i<<": "<<value[i]<<endl;
        }
    }

    void add_value(int v, int val)
    {
        value[v] = val;
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
    G->add_value(0,4);
    G->add_value(1,40);
    G->add_value(2,64);
    G->add_value(4,5);

    G->print();
    G->remove_edge(1, 4);
    return 0;
}
