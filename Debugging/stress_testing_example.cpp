/* Lets Problem be: Finding the second maximum in the array 
How to use the Stress Stesting in this

 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// your optimal one 
ll solve(ll n, vector<ll>&arr)
{

    ll res;
    if(n<=1)
        return -1;

    sort(arr.begin(), arr.end());
    return arr[n-2];
}

// bruitforce one
ll bruitforce(ll n, vector<ll>&arr){
    ll max,sm,i;
    max=arr[0];
    for(i=0;i<n;i++){   
        if(arr[i]>max)
            max=arr[i];
    }
    sm=-1;
    for(i=0;i<n;i++)
    {
        if(arr[i]!=max && arr[i]>sm)
            sm=arr[i];
    }
    return sm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL)); // will clear the seeding 
    // Note: this need to be called once.

    // contraints:
    // 1<t<100
    // 1<n<10
    //1< a[i]<10
    ll t;
    t=rand()%100+1; // +1 so that testcase does not become zero
    while (t--)
    {
        ll n;
        n=rand()%10+1;
        vector<ll>arr;
        for(ll i=0;i<n;i++){
            ll x;
            x=rand()%10+1;
            arr.emplace_back(x);
           
        }
        // feed the same test case to both the solution see the output of them
        if(solve(n,arr)!=bruitforce(n, arr)){
            for(auto it:arr){
                cout<<it<<" ";
            }
            cout<<endl;
            cout<<"your answer: "<<solve(n,arr)<<" Expected answer: "<<bruitforce(n, arr)<<endl;
        }
    }
    return 0;
}