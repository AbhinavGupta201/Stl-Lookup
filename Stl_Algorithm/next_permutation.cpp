/*
This stl algo is used to find next lexicographical permutation of an iterable container

Note: return true if the next exist and update the container to next else return false

*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Syntax: next_permutation(begin_iterator, end_iterator)
    // return true if next lexicographical permutation is there else false
    // modifies the container to the next permutation
    int arr[] = {1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    // in the array
    next_permutation(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    // in String
    string s = "language";
    next_permutation(s.begin(), s.end());
    cout << s << endl;

    // Q. How to Print all permutation?
    // A: first find the first permutation then use next permutation till it return false

    string str = "bca";
    // All permutation of the str
    cout<<"all Permutation \n";
    sort(str.begin(), str.end());
    do
    {
        /* code */
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}
