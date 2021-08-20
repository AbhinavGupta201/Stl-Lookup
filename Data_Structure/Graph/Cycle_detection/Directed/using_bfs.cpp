/* Directed cycle detection using the bfs traversal */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool explore(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recstack, int v)
{
    queue<int> q,q1;
    q.push(v);
    while (q.empty() != true)
    {
        int v = q.front();
        q.pop();
        recstack[v] = true;
        for (auto it : adj[v])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                if (explore(adj, visited, recstack, it))
                    return true;
            }
            else if(recstack[v])
                return true;
        }
        q1.push(v);
    }
    while (q1.empty()!=true)
    {
        int v=q1.front();
        recstack[v]=false;
        q1.pop();
    }
    return false;
}

bool bfs(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V + 1, false);
    vector<bool> recstack(V + 1, false);
    for (int i = 0; i < V + 1; i++)
    {
        if (explore(adj, visited, recstack, i))
            return true;
    }
    return false;
}

int main()
{
    int V, E, x, y, i, j;
    cout << "Enter the number of vertex and edges in the graph\n";
    cin >> V;
    cin >> E;
    vector<vector<int>> adj(V + 1);
    if (E != 0)
    {
        cout << "Enter all edges u, v one on each line \n";
        for (i = 0; i < E; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
        }
    }
    bool res = bfs(adj, V);
    if (res)
    {
        cout << "has cycle";
    }
    else
        cout << "no cycle in the graph\n";
    return 0;
}