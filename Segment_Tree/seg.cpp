
/* 
segtree Tree: This is a binary tree which store the data at the leaf of the binary tree and result of the segtree for what we are calculating as the parent node of the chilren 

    ex: for segtree tree of sum it is : 
                         10       --  result of its children 
                        /  \
                       7    3     --> segtree result (sum of children )
                      / \   / \
                     2  5  2   1  ---> actual data 
        
    Note: we always make the size of the segtree tree as the perfect for that we keep the size of the data as the power of 2. if it is not we make to nearest larger power of 2 by inserting some 0's at the end of the data.

    Q. When to use the segtree tree;
    Ans: segtree tree is often used for the range query(that we have to calculate something with some range say, [l,r) repeatedly in loop of update and calculate )

    Note: here is 2 types of operation:
        1. set(i,v): set the a[i] with the value v
        2. query(l,r): perform the query in the range of [l,r)




*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct segtree
{
    // data- structure
    ll size;
    vector<ll> seg;

    // constructor
    segtree(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        // assign is used to assign a single value or to the whole of the array
        // syntax: assign(size, value)
        seg.assign(2 * size, 0);

    }

    // build the segment tree in O(n) time complexity as every node is visited exactly once 
    void build(vector<ll>&a, ll x, ll lx, ll rx){
        if(rx-lx==1){
            // to check if it a valid position of the vector array 
            if(lx<a.size()){
                seg[x]=a[lx];
            }
            return ;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a, 2*x+2, m,rx);
        seg[x]=seg[x+1]+seg[x+2];
    }

    void build(vector<ll>&a)
    {
        build(a,0,0,size);
    }

    // set the segtree tree
    // set index i with the value time complexity: O(logN)
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return ;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x]=seg[2*x+1]+seg[2*x+2];
    }

    void set(ll i, ll val)
    {
        set(i, val, 0, 0, size);
    }

    ll sum(ll l,ll r, ll x, ll lx, ll rx){
        if(lx>=r ||  rx<=l)
            return 0;
        if(lx>=l && rx<=r)  return seg[x];
        ll s1,s2;
        ll m=(lx+rx)/2;
        s1=sum(l,r,2*x+1,lx,m);
        s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    ll sum(ll l, ll r){
        return sum(l,r,0,0,size);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    segtree *st = new segtree(n);
    for(ll i=0;i<n;i++){
        ll v;
        cin>>v;
        st->set(i,v);
    }
    st->print();
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll sum= st->sum(l,r);
        cout<<sum<<endl;
    }

    return 0;
}