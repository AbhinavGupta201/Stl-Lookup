/* sort:function is used to sort the linear container element 
Note: by default it sort in increasing order 
1. It is present in the algorithm header file
2.

Header file: algorithm 

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // Syntax sort(begin_iterator, end_iterator, [comparator])
    // comparator is completely optional
    int arr[]={3,2,5,4,1};
    int n=sizeof(arr)/sizeof(int);

    sort(arr, arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // for vector
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(2);

    sort(vec.begin(), vec.end());

    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;

}