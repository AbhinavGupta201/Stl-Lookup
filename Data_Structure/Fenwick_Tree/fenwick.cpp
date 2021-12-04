/* Fenwick tree is a data structre, which is used to perform the two types of operation 
1. Update(i , x): update the particular index with the new value x or add to that index
2. Range Query(l,r): perform some query between the range (l to r): like sum , multiplication and extra

Or in general all those operation which are associative and cumutative
associative : a*(b*c)== (a*b)*c 
cumutative: a*b == b*a;

Time complexity: Log(N); both update and query
Space Complexity: O(N): for storing the fenwick tree
we use the array to store the fenwick tree data

Implementation:
update(i, x) :
    // find the all the index of the ft which include the i and update them
    to find the all index
    do 
        ft[i]+=x;
        1. find the 2's complement of the i
        2. do & with the original 
        3. add it to the original 
        (or in short  : i=i+(i&(-i)))
    while(i<=N)

sum(int i) :
    // return the sum from the [1..i];
    we have to write the i as the sum of power of 2's 
    like for 13: 8+4+1
            i.e (1,8)+ (9, 12) + (13, 13) -- sum of those range 
    or the other simple way to find the all those index which make the (1,8) , (9, 12) , (13, 13) is
    do 
        res+=ft[i]
        1. find the 2's complement of the i
        2. do & with the original 
        3. subtract from original 
        (or i=i&(i-1) or i=i-(i&(-i)))
    while(i>0)


*/
#include<iostream>
#include<vector>
using namespace std;

struct Fenwick_Tree{
    int N; // to store the size
    vector<int>ft; // array to store the data

    Fenwick_Tree(int n){
        N=n; // size of array or max limit
        ft.assign(N+1, 0);
    }

    // update(i, x) : increase the value at the index i with the x
    void update(int i, int x){
        if(i<1 || i>N)
            return ;
        while (i<=N)
        {
            ft[i]+=x;
            i=i+(i&(-i));
        }
    }
    // it will return the subresult from the l=0 to r=i, can be either multiplication or sum or any thing for which you have formed the fenwick tree
    int sum(int i){
        int res=0;
        while(i>0){
            res+=ft[i];
            i=i&(i-1);
        }
        return res;
    }

    // query(l,r): return the query result from the l to r
    int query(int l, int r){
        return sum(r)-sum(l-1);
    }

    void print(){
        for(int i=1;i<=N;i++){
            cout<<ft[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    int t, n, i,j,op,x, l,r;
    cin>>n;
    cin>>t; 
    Fenwick_Tree *ft=new Fenwick_Tree(n);
    while (t--)
    {
        cin>>op;
        if(op==1){
            cin>>i>>x;
            ft->update(i,x);
        }
        else{
            cin>>l>>r;
            int res;
            res=ft->query(l,r);
            cout<<res<<endl;
        }
        ft->print();
    }
    return 0;
    
    
}