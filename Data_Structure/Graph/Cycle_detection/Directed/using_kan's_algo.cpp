/* 
                            Directed cycle detection using Kan's Algorithm
-------------------------------------------
topological Sorting: it a way of sorting so that every edges go from left to right if nodes are aligned in the horizontal line 
or
assume every node as the job and edges between them as the dependency like u---->v 
then u and v are the two job and v is dependent on the u.
so the rule is : before any job all of its dependent should be done before.
--------------------------------
Note: it is only applicable in the case of the acyclic graph

This algorithm is known as the Kan's Algorithm (used in the directed cycle detection with a slight modification )
 
Time Complexity: O(V+E)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// this function will calculate the indegree of the vertex
void calc_indegree(vector<vector<int>> &adj, vector<int> &indegree, int V)
{
    /* 
    This will calculate the outdegree not the indegree

    for(int i=1;i<=V;i++){
        indegree[i]=adj[i].size();
    } */
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }
}

// topological sort using kan's algorithm
bool bfs_topo(vector<vector<int>> &adj, int V)
{
    vector<int> indegree(V + 1, 0);
    calc_indegree(adj, indegree, V);
    queue<int> q;
    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (q.empty() != true)
    {
        int v;
        v = q.front();
        q.pop();
        count++;
        for (auto i : adj[v])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return (count != V);
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
    bool res = bfs_topo(adj, V);
    if (res)
        cout << "has directed cycle\n";
    else
        cout << "no directed cycle\n";
    return 0;
}