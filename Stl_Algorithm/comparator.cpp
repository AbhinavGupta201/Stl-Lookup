/*

"Comparator” are the function which returns boolean value, whether to swap two element or not
Note: This is passed as the third parameter where we want the our own way of structuring the things

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// this are the simple function with the boolean return type and takes elements of datatypes of the container
// Have the logic to arrange the things you want to !!!
bool comp(int a,int b){
    // cout<<"a="<<a<<" b="<<b<<endl;
    // second argument element is left one::
    // first argument element is right one ::
    if(b < a)
        return true;
    return false;
}

/* 
Note: Position are:     b   a
                        n  n+1
        If you return TRUE then it will swap a and b 
        else do not 
*/
int main(){
        int arr[]={3,1,6,4,6,2,1,4};
        int n=sizeof(arr)/sizeof(int);

        // For array on sorting 
        sort(arr, arr+n,comp);
        cout<<"after sorting using comparator: ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
}