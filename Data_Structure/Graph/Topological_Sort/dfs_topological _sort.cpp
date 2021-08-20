/* Dfs topological sorting
-------------------------------------------
topological Sorting: it a way of sorting so that every edges go from left to right if nodes are aligned in the horizontal line 
or
assume every node as the job and edges between them as the dependency like u---->v 
then u and v are the two job and v is dependent on the u.
so the rule is : before any job all of its dependent should be done before.
--------------------------------
Note: it is only applicable in the case of the acyclic graph

we can do it using either dfs or the bfs sorting algorithm. 
1. This is Dfs implementation 

 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topo_explore(vector<vector<int>>&adj, vector<bool>&visited, stack<int>&st, int v){
    for(auto u:adj[v]){
        if(visited[u]==false){
            visited[u]=true;
            topo_explore(adj, visited, st, u);
        }
    }
    st.push(v);

}
void dfs_topo(vector<vector<int>>&adj, int V){
    stack<int>st;
    vector<bool>visited(V+1, false);
    for(int i=1;i<=V;i++){
        if(visited[i]==false)
        {
            visited[i]=true;
            topo_explore(adj, visited, st, i);
        }
    }
    while (st.empty()!=true)
    {
        int u;
        u=st.top();
        st.pop();
        cout<<u<<" ";
    }
    cout<<endl;
    

}
int main(){
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
    dfs_topo(adj, V);
    return 0;
}