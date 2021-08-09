/* 
Graph : is a non linear data structure. Which is a collection of vertex set, V and edges set E.

there are three way to represent the graph
1. Adjacency List: In this every node is a root of the linked list at the all edges have this edges are the node of this linked list

// Note: for weighted graph add a extra feild of weight in the node structure
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    // data structre
    int data;
    node *next;

    // constructor
    node()
    {
        data = 0;
        next = NULL;
    }

    node(int x)
    {
        data = x;
        next = NULL;
    }

    node(int x, node *nextptr)
    {
        data = x;
        next = nextptr;
    }
};

struct Graph
{
    // Data Structure
    int V;      // number of vertex
    int E;      // number of edge
    node **adj; // adj list for storing the array of the root node
    int *value; // to store value associated with the node if any

    // Constructor
    Graph(int v, int e)
    {
        V = v;
        E = e;
        adj = (node **)calloc((V + 1), sizeof(node *));
        value = (int *)calloc((V + 1), sizeof(int)); // calloc: initilise with the 0 (by default) and create specified number of the blocks
    }

    // add edge
    void add_edge(int x, int y)
    {
        node *n = new node(x);
        node *m = new node(y);
        node *temp;
        temp = adj[x]; // copy of the adj[x] is assigned to the temp so changed won't reflect in adj[x] by assigning to temp
        if (temp == NULL)
        {
            // temp=m; won't work
            adj[x] = m;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = m;
        }

        temp = adj[y];
        if (temp == NULL)
        {
            adj[y] = n;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    // remove edge
    void remove_edge(int x, int y)
    {
        node *temp;
        temp = adj[x];
        if (temp != NULL)
        {
            if (temp->data == y)
                temp = NULL;
            else
            {
                while (temp->next != NULL && temp->next->data != y)
                {
                    temp = temp->next;
                }
                if (temp->next != NULL)
                {
                    node *t;
                    t = temp->next;
                    temp->next = t->next;
                    free(t);
                }
            }
        }
        temp = adj[y];
        if (temp != NULL)
        {
            if (temp->data == x)
                temp = NULL;
            else
            {
                while (temp->next != NULL && temp->next->data != x)
                {
                    temp = temp->next;
                }
                if (temp->next != NULL)
                {
                    node *t;
                    t = temp->next;
                    temp->next = t->next;
                    free(t);
                }
            }
        }
    }

    // add_value(): add value corresponding to the ith node
    void add_value(int i, int val)
    {
        value[i] = val;
    }

    // for debugging purpose only :
    void print()
    {

        cout << "adj list: \n";
        for (int i = 0; i <= V; i++)
        {
            cout << i << " : ";
            for (node *t = adj[i]; t != NULL; t = t->next)
            {
                cout << t->data << " ";
            }
            cout << endl;
        }
        // node value:
        cout << " \tnode value: \n\n";
        cout << "node:\t";
        for (int i = 1; i <= V; i++)
        {
            cout << i << "\t";
        }
        cout << endl;
        cout << "value:\t";
        for (int i = 1; i <= V; i++)
        {
            cout << value[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    Graph *G = new Graph(5, 3);
    G->add_edge(2, 1);
    G->add_edge(1, 4);
    G->add_edge(3, 4);
    G->add_edge(4, 5);
    G->add_edge(2, 3);
    G->remove_edge(2, 3);
    G->add_value(1, 4);
    G->add_value(3, 5);
    G->add_value(5, 10);

    G->print();
    return 0;
}