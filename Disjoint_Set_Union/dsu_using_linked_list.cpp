/* 
In this approach of implementing the Disjoints sets union: has the time complexity of the 
get(a): O(1) 
union(a,b): O( logN) 

Note: Although it is slower than the path-compression based implementation, but has the facility that it can even give the what all element are there in the set.(Maintane the set element also )
Along with the other associative and commutative function . 

*/

#include <iostream>
using namespace std;

struct node
{
    int data;   // to store the data
    node *next; // pointer to the next element

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
};

struct DSU
{
    int n;     // for number of element
    node **l;  // leader array where each element will be a linked list of set elements
    int *size; // size of the set
    int *p;    // leader of the element for

    // constructor
    DSU(int N)
    {
        n = N;
        l = (node **)malloc(sizeof(node *) * (n + 1)); // to store the size of the array
        size = (int *)calloc((n + 1), sizeof(int));    // size of the set
        p = (int *)malloc(sizeof(int) * (n + 1));
        for (int i = 0; i <= n; i++)
        {
            node *t = new node(i);
            l[i] = t;
            size[i] = 1; // size of each set is 1
            p[i] = i;    // each element is in it's own set
        }
    }

    // get(a): return the leader of the set to which it belong
    // Time Complexity: O(1)
    int get(int a)
    {
        return p[a];
    }

    // union(a, b): join the two set to which two which a and b belong
    // Time-Complexity: O(logN )
    void Union(int a, int b)
    {
        a = p[a];   // leader of set to which a belong to
        b = p[b];   // leader of set to which b belong to
        if (a == b) // they are in the same set
            return;
        if (size[a] > size[b])
            swap(a, b);
        node *t;
        for (t = l[a]; t != NULL; t = t->next)
        {
            p[t->data] = b;
        }
        for (t = l[b]; t->next != NULL; t = t->next)
        {
        }
        t->next = l[a];
        size[b] += size[a];
    }

    // print: for debugging purpose
    void print(){
       /*  for(int i=0;i<=n;i++){
            node *t;
            cout<<i<<". ";
            for(t=l[i];t!=NULL;t=t->next)
                cout<<t->data<<" ";
            cout<<endl;
        } */
        for(int i=0;i<=n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int n;
    cin >> n;
    DSU *ds = new DSU(n);
    int m, a, b;
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        ds->Union(a, b);
        ds->print();
    }
    cout << endl
         << ds->get(2) << endl;
    return 0;
}