/* 
Bfs topological sorting
-------------------------------------------
topological Sorting: it a way of sorting so that every edges go from left to right if nodes are aligned in the horizontal line 
or
assume every node as the job and edges between them as the dependency like u---->v 
then u and v are the two job and v is dependent on the u.
so the rule is : before any job all of its dependent should be done before.
--------------------------------
Note: it is only applicable in the case of the acyclic graph

we can do it using either dfs or the bfs sorting algorithm. 
1. This is Bfs implementation 

This algorithm is known as the Kan's Algorithm (also used in the directed cycle detection with a slight modification )
 
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// this function will calculate the indegree of the vertex
void calc_indegree(vector<vector<int>>&adj, vector<int>&indegree, int V){
    /* 
    This will calculate the outdegree not the indegree

    for(int i=1;i<=V;i++){
        indegree[i]=adj[i].size();
    } */
    for(int i=1;i<=V;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    for(int i=1;i<=V;i++){
        cout<<indegree[i]<<" ";
    }
    cout<<endl;
}

// topological sort using kan's algorithm 
void bfs_topo(vector<vector<int>>&adj, int V){
    vector<int>indegree(V+1,0);
    calc_indegree(adj, indegree, V);
    queue<int>q;
    for(int i=1;i<=V;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while (q.empty()!=true)
    {
        int v;
        v=q.front();
        cout<<v<<" ";
        q.pop();
        for(auto i:adj[v]){
            indegree[i]--;
            if(indegree[i]==0)
                q.push(i);
        }
    }
    cout<<endl;
    
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
    cout<<"topological sort: ";
    bfs_topo(adj, V);
    return 0;
}