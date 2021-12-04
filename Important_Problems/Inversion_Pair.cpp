/* 
Given an array A
Q.You need to find the number of inversin pair are there in the array
Inversion pair: two indexes i, j are said to be inversion point if
    i<j && a[i]> a[j] 

Bruit force: check for all pair using two loops 
time complexity: O(n^2)

optimal solution: 
1. use the merge sort. 
    time complexity: O(nlogn) 
    space complexity: O(N)
    modify the array you don't use the temp array

2. Using fenwick tree: 
    time complexiy: O(NlogN)
    space complexity: O(N)
    don't modify the array 
*/
#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>&a, int l, int r){
    if(l>=r)
        return 0;
    int res=0,mid,i,j;
    mid=(l+r)>>1;
    i=l;
    j=mid+1;
    vector<int>temp;
    while (i<=mid && j<=r)
    {
        if(a[i]>a[j]){
            res+=mid-i+1;
            temp.push_back(a[j]);
            j++;
        }
        else{
            temp.push_back(a[i]);
            i++;
        }
    }
    while (i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while (j<=r)
    {
        temp.push_back(a[j]);
        j++;
    }
    for(i=0;i<temp.size();i++){
        a[l+i]=temp[i];
    }
    return res;
}

int mergeSort(vector<int>&a, int l, int r){
    if(l>=r)
        return 0;
    int mid=(l+r)>>1;
    int res=0;
    res+=mergeSort(a, l,mid);
    res+=mergeSort(a,mid+1, r);
    return res+merge(a, l, r);
}

int findInversionPairs(vector<int>&a, int n){
    return mergeSort(a,0,n-1);
}

int main(){
    int n,i,res;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    res=findInversionPairs(a, n);
    cout<<"no of inversion pairs: "<<res<<endl;
    for ( i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl; 
    
    return 0;
}