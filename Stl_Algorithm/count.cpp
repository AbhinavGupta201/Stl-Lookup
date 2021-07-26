/* This stl algo is used to count the no of occourance of a element in the iterable container

Note: return the count 
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Syntax:
    // count(begin_itertor, end_iterator, x);

    int arr[] = {5, 3, 6, 9, 10, 25, 3};
    vector<int> vec = {5, 2,2,2, 6, 9, 10, 4, 3};

    // in array's
    int res  = count(arr, arr + 7,1);
    cout<<"count of 1 in array: "<<res<<endl;

    res  = count(arr, arr + 7,3);
    cout<<"count of 3 in array: "<<res<<endl;

    // For Vector
    res  = count(vec.begin(), vec.end(),2);
    cout<<"count of 2 in vector: "<<res<<endl;

    return 0;
}