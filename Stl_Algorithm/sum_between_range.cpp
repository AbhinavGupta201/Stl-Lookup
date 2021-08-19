/*
 This stl algo is used to find sum between the specified range of the iterable container

 Function: accumulate()
 Header file: numeric

 Note: return type of the accumulate is int so it may give overflow value for the long long int value so be careful while using it.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include<numeric>
using namespace std;

int main()
{
    // Syntax:
    // accumulate(begin_iterator, end_iterator, initial_sum)

    int arr[] = {5, 3, 6, 9, 10, 25, 3};
    vector<int> vec = {5, 2, 6, 9, 10, 4, 3};

    int sum=accumulate(arr,arr+7,0);
    cout<<"array sum is: "<<sum<<endl;
    
    sum=accumulate(vec.begin(), vec.end(),0);
    cout<<"vec sum is: "<<sum<<endl;

    return 0;
}