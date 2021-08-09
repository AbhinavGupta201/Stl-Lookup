/* 
Graph : is a non linear data structure. Which is a collection of vertex set, V and edges set E.

there are three way to represent the graph
1. Adjacency List: In this every node is a root of the linked list at the all edges have this edges are the node of this linked list
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    // data structre
    int data;
    node *next;

    // constructor
    node(){
        data=0;
        next=0;
    }

    node(int x){
        data=x;
        next=NULL;
    }

    node(int x, node *nextptr){
        data=x;
        next=nextptr;
    }
};

struct Graph{
    // Data Structure
    int V; // number of vertex 
    int E; // number of edge
    node *adj; // adj list for storing the array of the root node 

    // Constructor
    Graph(int v,int e)
    {
        V=v;
        E=e;
        adj=(node *)malloc(sizeof(node)*(V+1));
        for (int i = 0; i < V; i++)
        {
            node *temp;
            temp=adj+i;
            cout<<i<<". ";
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                if(temp->next==NULL)
                    cout<<"--NULL ";
                else 
                    cout<<" Not NULL  ";
                temp=temp->next;
            }
            cout<<endl;
            
        }
        
    }

    // add edge
    void add_edge(int x, int y){
        node *n=new node(x);
        node *m=new node(y);
        node *temp;
        // temp=adj[x];
        // if(temp==NULL)
        //     adj+x=n;
        // while (adj[x]->next!=NULL)
        // {
        //     /* code */adj[x]
        // }
        
    }

};

int main(){
    Graph *G=new Graph(3,5);
    return 0;

}