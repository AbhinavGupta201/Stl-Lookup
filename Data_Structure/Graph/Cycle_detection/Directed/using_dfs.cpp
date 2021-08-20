/* Directed Cycle Detection Using Dfs 
Note: here we require a extra recursion call stack to keep track of what all nodes have been visited
int that explore function call.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool explore(vector<vector<int>> &adj, vector<bool> &visited, vector<bool>&recstack, int s)
{
    recstack[s]=true;
    for (auto i : adj[s])
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            if (explore(adj, visited,recstack, i))
                return true;
        }
        else if (recstack[i] == true)
            return true;
    }
    recstack[s]=false;
    return false;
}
bool dfs(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V + 1, false);
    vector<bool> recstack(V+1, false);
    for (int i = 1; i <= V; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            if (explore(adj, visited,recstack, i))
                return true;
        }
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
    bool res = dfs(adj, V);
    if (res)
    {
        cout << "has cycle";
    }
    else
        cout << "no cycle in the graph\n";
    return 0;
}