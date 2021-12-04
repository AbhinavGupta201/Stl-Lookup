#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t,n,i;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            if(i<n/2)
                freq[s[i]-'a']++;
            else
                freq[s[i]-'a']--;
        }
        if(n%2==1) // odd length string
        {
            freq[s[n/2]-'a']++;
        }
        for( i=0;i<26;i++){
            if(freq[i]!=0)
                break;
        }
        if(i==26)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}