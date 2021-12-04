#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
bool isPrime(int n){
    if(n==1 || n==0)
        return false;
    else if(n==2)
        return true;
    for (int i = 2; i < sqrt(n)+1; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    if(isPrime(n))
        cout<<"Prime\n";
    else 
        cout<<"Not Prime"<<endl;

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