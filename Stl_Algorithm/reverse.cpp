/*
reverse(): stl is used to reverse any iterable container 

 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int main(){
    int arr[]={1,5,4,2,4};
    int n=sizeof(arr)/sizeof(int);
    // Syntax: reverse(begin_iterator, end_iterator)
    // for array
    cout<<"Array : ";
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // for vector
    vector<int>vec;
    vec.emplace_back(3);
    vec.emplace_back(1);
    vec.emplace_back(5);
    vec.emplace_back(6);

    cout<<"\nvector :";
    reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        cout<<vec.at(i)<<" ";
    }

}