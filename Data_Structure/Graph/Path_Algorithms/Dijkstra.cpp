/* Dijkstra's Algo
This algorithm is used to find the single source shortest path
Time complexity: O()

*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Dijkstra(vector<vector<int>> &adj, int V, int source)
{
    // syntax of the min priority queue priority_queue< T, vector<T>, greater<T> >pq;
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(10);
    pq.push(5);
    while (pq.empty() != true)
    {
        int v;
        v = pq.top();
        pq.pop();
        cout << v << " ";
    }
    cout << endl;
}
int main()
{
    int V, E, x, y, w, i, j;
    cout << "Enter the number of vertex and edges in the graph\n";
    cin >> V;
    cin >> E;
    vector<vector<int>> adj(V + 1);
    vector<vector<int>> weight(V + 1, vector<int>(V + 1, 0));
    if (E != 0)
    {
        cout << "Enter all edges u, v w(weight of the edge) one on each line \n";
        for (i = 0; i < E; i++)
        {
            cin >> x >> y >> w;
            adj[x].push_back(y);
            weight[x][y] = w;
        }
    }
    Dijkstra(adj, V, 0);
}