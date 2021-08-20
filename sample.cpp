#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
long long calc_sum(auto it, auto end,ll initial)
{
    while(it!=end){
        initial++*it;
        it++;
    }
    return initial;
}
void solve(){
    vector<ll>a;
    a.push_back(39);
    a.push_back(10);
    cout<<calc_sum(a.begin(), a.end(), 0)<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}