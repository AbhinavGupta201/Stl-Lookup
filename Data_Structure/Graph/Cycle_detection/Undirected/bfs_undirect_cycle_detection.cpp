/* using bfs */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool explore(vector<vector<int>>&adj, vector<bool>&visited, int V,int s){
    vector<int>parent(V+1,-1);
    queue<int>q;
    q.push(s);
    while(q.empty()!=true){
        int v;
        v=q.front();
        q.pop();
        for(auto i:adj[v]){
            if(visited[i]==false){
                visited[i]=true;
                parent[i]=v;
                q.push(i);
            }
            else{
                if(i!=parent[v])
                    return true;
            }
        }
    }
    return false;
}

bool bfs(vector<vector<int>>&adj, int V){
    vector<bool>visited(V+1, false);
    for(int i=1;i<=V;i++){
        if(visited[i]==false )
        {
            visited[i]=true;
            if(explore(adj, visited, V, i))
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
    bool res=bfs(adj, V);
    if(res){
        cout<<"has cycle";
    }
    else
        cout<<"no cycle in the graph\n";
    return 0;

}