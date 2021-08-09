/* 
Graph : is a non linear data structure. Which is a collection of vertex set, V and edges set E.

there are three way to represent the graph
1. Adjacency Matrix: it store the all the edges relation in a 2D matrix of size n*n where n is number of nodes in the graph 
Note: further it can be directed or undirected

                        ~~~~~~~~~~~~~~~Undirected Adjacency Matrix Implementation~~~~~~~~~~~~
                                                    Note: for weighted Directed graph 
                            just add value of the edge corresponding to the adj matrix in place of 1.

*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Graph{
    // Data Structure
    int V; // number of vertex 
    int E; // number of edge
    int **adj; // adj list for storing the array of the root node 
    int *value; // to store value associated with the node if any 

    // Constructor
    Graph(int v,int e)
    {
        V=v;
        E=e;
        adj=(int **)malloc(sizeof(int*)*(V+1)); // create a single block of the specified size . and initise with the garbage value
        value=(int *)calloc((V+1),sizeof(int)); // calloc: initilise with the 0 (by default) and create specified number of the blocks 

        for (int i = 0; i < V+1; i++)
        {
            adj[i]=(int *)calloc((V+1),sizeof(int*));    
        }
    }

    // add edge (x, y) to the graph
    void add_edge(int x, int y){
        adj[x][y]=1;
        adj[y][x]=1;
    }

    // remove edge(x, y): remove edge x---y 
    void remove_edge(int x, int y){
        adj[x][y]=0;
        adj[y][x]=0;
    }

    // add value: add any value to the node i, if any 
    void add_value(int i, int x){
        value[i]=x;
    }

    // for debugging purpose only 
    void print(){
        cout<<"\t adj matrix: \n\n";
        cout<<"\t";
        for(int i=1;i<=V;i++){
            cout<<i<<"\t";
        }
        cout<<endl;
        cout<<"\t";
        for(int i=1;i<=V;i++){
            cout<<"_\t";
        }
        cout<<endl<<endl;
        for(int i=1;i<=V;i++){
            cout<<i<<" |\t";
            for (int j = 1; j <=V; j++)
            {
                cout<<adj[i][j]<<"\t";
            }
            cout<<endl<<endl;
            
        }

        // node value:
        cout<<" \tnode value: \n\n";
        cout<<"node:\t";
        for(int i=1;i<=V;i++){
            cout<<i<<"\t";
        }
        cout<<endl;
        cout<<"value:\t";
        for (int i = 1; i <= V; i++)
        {
            cout<<value[i]<<"\t";
        }
        cout<<endl;
    
    }

};

int main(){
    Graph *G=new Graph(3,3);
    G->add_edge(2,1);
    G->add_edge(1,3);
    G->remove_edge(2,3);
    G->add_edge(2,3);
    G->add_value(1,4);
    G->add_value(2,5);
    G->add_value(3, 10);

    G->print();
    return 0;
}