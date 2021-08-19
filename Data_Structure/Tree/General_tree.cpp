/* Tree is a hierarchical data structure and store the parent child relationship 
Property:
1. it's acyclic.
2. For n vertex there is n-1 edges
3. There is unique path between the two point u and v. 

Defination: A tree is a non linear data structure in which there is a special node called root node and it's children's can be divided into n>=0 number of disjoint ordered set.

Types :
1. Binary Tree: there will be atmost two childs for each node 
2. General Tree : can have any number of childs
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef int item;
struct Tree
{
    long long n;              // number of vertex count
    long long root = 1;       // root of the tree
    vector<item> a;           // to store the value at each of the node
    vector<vector<item>> adj; // to store the adjencency list info i.e for adj[i][j] if there then there is a node front i to adj[i][j]

    // constructor
    Tree(long long ver, long long rooted=1)
    {
        n = ver;
        root = rooted;
        a.resize(n + 1, 0);
        adj.resize(n + 1);
    }

    // add edge to the tree
    void add_edge(long long x, long long y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // remove an edge 
    void remove_edge(long long x, long long y)
    {
        bool flage = false;
        for (long long i = 0; i < adj[x].size(); i++)
        {
            if (adj[x][i] == y)
            {
                flage = true;
            }
            if (flage)
            {
                adj[x][i]=adj[x][i+1];
            }
        }
        if(flage)
            adj[x].pop_back();
        
        flage = false;
        for (long long i = 0; i < adj[y].size(); i++)
        {
            if (adj[y][i] == x)
            {
                flage = true;
            }
            if (flage)
            {
                adj[y][i]=adj[y][i+1];
            }
        }
        if(flage)
            adj[y].pop_back();        
    }

    // add value corresponding to the node 
    void add_value(long long i,long long val){
        a[i]=val;
    }
};

int main()
{
    long long n, m, x, y, i;
    cin >> n;
    Tree *t = new Tree(n);
    for(i=1;i<=n;i++)
    {
        cin>>x;
        t->add_value(i,x);
    }
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        t->add_edge(x, y);
    }

    cout<<"tree is : \n";
    for(i=1;i<=n;i++)
    {
        cout<<t->a[i]<<" ";
    }
    cout<<endl<<" Edges are: \n";
    for(i=1;i<=n;i++){
        for(long long j=0;j<t->adj[i].size();j++){
            cout<<i<<"----"<<t->adj[i][j]<<endl;

        }
    }
    
    return 0;
    
}
