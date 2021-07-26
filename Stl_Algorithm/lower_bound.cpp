/*
This stl algo is used to find First element which is not less than x iterable container

Note: container should be sorted to work this stl algo 
Note: return the iterator to the element if exist else end() iterator

Note: Behind it uses the Binary Search algo ...

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Syntax:
    // container should be sorted
    // lower_bound(begin_itertor, end_iterator, x);
    // return iterator( to first element else end() iterator)
    int n,index,res;
    int arr[] = {5, 10, 13, 26, 59};
    vector<int> vec = {5, 12, 20, 30, 60, 90, 100};
    n = sizeof(arr) / sizeof(int);

    // in array's
    auto it = lower_bound(arr, arr + 7, 19);
    if (it == arr+n)
        cout << "element do not exist" << endl;
    else
        cout << "element is: " << *it << endl;

    // For Vector
    auto ptr = lower_bound(vec.begin(), vec.end(), 132);
    if (ptr == vec.end())
        cout << "element do not exist" << endl;
    else
        cout << "element is: " << *ptr << endl;

    return 0;
}