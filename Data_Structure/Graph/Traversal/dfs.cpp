/* Dfs(depth first search ) */
#include<vector>
#include<iostream>
using namespace std;

void explore(vector<vector<int>>&adj, vector<bool>& visited, int s){
    cout<<s<<" ";
    for(auto it:adj[s]){
        if(visited[it]==false){
            visited[it]=true;
            explore(adj, visited, it);
        }
    }
}
void dfs(vector<vector<int>>&adj, int V, int s){
    vector<bool>visited(V+1, false);
    int count=0; // counting the number of component the given graph has
    visited[s]=true;
    explore(adj, visited, s);
    count=1;
    for(int i=1;i<=V;i++)
    {
        if(visited[i]==false){
            visited[i]=true;
            count++;
            explore(adj, visited, i);
        }
    }
    cout<<"\nNo of component is : "<<count<<endl;
}
int main(){
    int V,E,x,y,i,j;
    cout<<"Enter the number of vertex and edges in the graph\n";
    cin>>V;
    cin>>E;
    vector<vector<int>>adj(V+1);
    cout<<"Enter all edges u, v one on each line \n";
    for(i=0;i<E;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int start;
    cout<<"enter the starting vertex for the dfs \n";
    cin>>start;
    cout<<"dfs is: ";
    dfs(adj, V, start );
    cout<<endl;
    return 0;

}