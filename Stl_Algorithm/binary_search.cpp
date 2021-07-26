/*
This stl algo is used to find whether element in present in iterable container or not 

Note: container should be sorted to work this stl algo 
Note: return the boolean (true if present else false)

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Syntax:
    // container should be sorted
    // binary_search(begin_itertor, end_iterator, x);
    // return boolean
    int n;
    int arr[] = {5, 10, 13, 26, 59};
    vector<int> vec = {5, 12, 20, 30, 60, 90, 100};
    n = sizeof(arr) / sizeof(int);

    // in array's
    bool it = binary_search(arr, arr + n, 9);
    if (it == false)
        cout << "element is not present" << endl;
    else
        cout << "element is present" << endl;

    // For Vector
    bool res = binary_search(vec.begin(), vec.end(), 20);
    if (res == false)
        cout << "element is not present" << endl;
    else
        cout << "element is present" << endl;

    return 0;
}