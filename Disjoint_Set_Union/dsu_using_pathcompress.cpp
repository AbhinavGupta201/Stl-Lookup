/* 
What is Disjoint Sets: sets a and b are said to be disjoint sets if there is no common element between them.

DSU is a data structure that supports disjoint sets on n elements and allows two type of queries:

    get(a) — return the identifier of the set to which a belongs to;
    union(a, b) — join two sets that contain a and b. 

Implementation : we store a p[] array for storing the what is the parent of the element
Terminology : 
1. identifier: it is the name for the set by which it will be identified ( for simplicity we assign it as the one of the element of the set and call that element as the leader of the set)

So, basically, p[i] give the parent of the element i, which is basically the set identifier to which it belong (leader of the set)


Note: Except for maintaining the sets,
    * we can support associative and commutative functions.
     An operation ⊗ is associative, if its result does not depend on the order of application, i.e., (a⊗b)⊗c=a⊗(b⊗c). 
     An operation ⊗ is commutative, if its result does not depend on the order of the arguments, i.e., a⊗b=b⊗a.

     we get that get and union work in O(α(m,n)) time amortized, where α(m,n) is the inverse Ackermann function, m is the number of performed operations get and n is the number of elements.

     a simple upper loose bound would be: O(log*N): This function means how many times we should take the binary logarithm of n to get a value smaller than one
*/
#include <iostream>
using namespace std;

struct dsu
{
    int N;     //currently number of the set are there
    int *p;    // to store the parent information
    int *size; // to store the size of the set

    // constructor
    dsu(int n)
    {
        N = n;
        p = (int *)malloc(sizeof(int) * (n + 1));
        size=(int *)calloc((n+1), sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
        }

        size = (int *)calloc((n + 1), sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
        }
    }

    // build the dsu
    void build_dsu(int x)
    {
        p[x] = x;
    }

    // get(): return the identifier for the set ( or the leader of the set )
    int Get(int a)
    {
        return p[a] = (p[a] == a ? a : Get(p[a]));
    }

    // union(a,b); will merge
    // Time Complexity: O(log∗n)
    void Union(int a, int b)
    {
        a = p[a];   // leader of a
        b = p[b];   // leader of b
        if (a == b) // if they have same leader, then they are in the same set, so nothing to do
            return;

        if (size[a] >= size[b]) // if number of element in a is greater than or equal to that of the b. then make the smaller set(that is b to be merge into the a )
        {
            p[b] = a;           // make leader of b as  a
            size[a] += size[b]; // increment the size of the new set generated.
        }
        else
        {
            p[a] = b;           // make the leader of a to be b.
            size[b] += size[a]; //increment the size of the new set generated.
        }
        // number of set count will decrease by 1.
    }

    // for debugging purpose only
    void print()
    {
        for (int i = 0; i <= N; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    dsu *ds = new dsu(n);
    int m, a, b;
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        ds->Union(a, b);
        ds->print();
    }
    cout << endl
         << ds->Get(2) << endl;
    return 0;
}