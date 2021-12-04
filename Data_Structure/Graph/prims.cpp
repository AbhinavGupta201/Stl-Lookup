/* Prims is a algorithm used to find the number of minimum spanning tree of the graph
Algorithm :
Assume two sets A and B. in set A there are those element which are in the mst while others which are not in the mst as set B. 
pick a vertex and add it to the set A .
now till set B is not empty()
do 
    pick a vertex from the set B whose edges weight from the set a is minimum. 
    and add that to the set A 
 */
#include<iostream>
#include<vector>
#include<set>
using namespace std;

void prims(vector<vector<int>>&adj, int V)
{
    int u,w, i,j, count;
    set<int>A;
    set<int>B;
    for(int i=1;i<=V;i++)
        B.insert(i);
    
}
int main(){
    int t , i,j, n, m;

}