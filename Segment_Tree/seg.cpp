
/* 
Segment Tree: This is a binary tree which store the data at the leaf of the binary tree and result of the segment for what we are calculating as the parent node of the chilren 

    ex: for segment tree of sum it is : 
                         10       --  result of its children 
                        /  \
                       7    3     --> segment result (sum of children )
                      / \   / \
                     2  5  2   1  ---> actual data 
        
    Note: we always make the size of the segment tree as the perfect for that we keep the size of the data as the power of 2. if it is not we make to nearest larger power of 2 by inserting some 0's at the end of the data.

    Q. When to use the segment tree;
    Ans: Segment tree is often used for the range query(that we have to calculate something with some range say, [l,r) repeatedly in loop of update and calculate )

    Note: here is 2 types of operation:
        1. set(i,v): set the a[i] with the value v
        2. query(l,r): perform the query in the range of [l,r)




*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct segment
{
    // data- structure
    ll size;
    vector<ll> seg;

    // constructor
    segment(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        // assign is used to assign a single value or to the whole of the array 
        // syntax: assign(size, value)
        seg.assign(size,0);
        
        cout<<seg.size()<<endl;
        for(auto it:seg){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    // set the segment tree
    // void set()
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    segment *st=new segment(n);

    return 0;
}