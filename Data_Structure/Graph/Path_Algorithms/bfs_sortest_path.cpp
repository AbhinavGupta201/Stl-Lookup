/* Bfs can be used to find the shortest path in the unweighted graphs
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void explore(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dist, int source)
{
    queue<int> q;
    q.push(source);
    while (q.empty() != true)
    {
        int v = q.front();
        q.pop();
        for (auto i : adj[v])
        {
            dist[i] = min(dist[i], dist[v] + 1);
            if (visited[i] == false)
            {
                visited[i] = true;
                explore(adj, visited, dist, i);
            }
        }
    }
}

vector<int> bfs(vector<vector<int>> &adj, int V, int s)
{
    vector<bool> visited(V + 1, false);
    vector<int> dist(V + 1, INT16_MAX);
    dist[s] = 0;
    visited[s] = true;
    explore(adj, visited, dist, s);
    return dist;
}

int main()
{
    int V, E, x, y, w, i, j, s;
    cout << "Enter the number of vertex and edges in the graph\n";
    cin >> V;
    cin >> E;
    vector<vector<int>> adj(V + 1);
    if (E != 0)
    {
        cout << "Enter all edges u, v w(weight of the edge) one on each line \n";
        for (i = 0; i < E; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(0);
        }
    }
    vector<int> res;
    cin >> s;
    res = bfs(adj, V, s);
    cout << "shortest path from " << s << ": is" << endl;
    for (i = 0; i < V; i++)
    {
        cout << i << ": " << res[i] << endl;
    }
    return 0;
}