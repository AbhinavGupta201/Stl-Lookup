/* Undirected cycle detection 
Using DFS
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool explore(vector<vector<int>>&adj, vector<bool>&visited, int s, int parent){
    for(auto i:adj[s]){
        if(visited[i]==false){
            visited[i]=true;
            if(explore(adj, visited, i, s))
                return true;
        }
        else if(visited[i]==true && i!=parent)
            return true;
    }
    return false;
}

bool dfs(vector<vector<int>>&adj, int V){
    vector<bool>visited(V+1, false);
    for(int i=1;i<=V;i++){
        if(visited[i]==false){
            visited[i]=true;
            if(explore(adj, visited, i,-1))
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
            adj[y].push_back(x);
        }
    }
    bool res=dfs(adj, V);
    if(res){
        cout<<"has cycle";
    }
    else
        cout<<"no cycle in the graph\n";
    return 0;

}