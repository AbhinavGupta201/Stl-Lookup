/*
This stl algo is used to find prev lexicographical permutation of an iterable container

Note: return true if the previous exist and update the container to prev else return false

*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Syntax: prev_permutation(begin_iterator, end_iterator)
    // return true if prev lexicographical permutation is there else false
    // modifies the container to the prev permutation
    int arr[] = {1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    // in the array
    prev_permutation(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    // in String
    string s = "language";
    prev_permutation(s.begin(), s.end());
    cout << s << endl;

    // Q. How to Print all permutation?
    // A: first find the first permutation then use prev permutation till it return false

    string str = "bca";
    // All permutation of the str
    cout<<"all Permutation \n";
    sort(str.begin(), str.end(), greater<char>());
    do
    {
        /* code */
        cout << str << endl;
    } while (prev_permutation(str.begin(), str.end()));
}
