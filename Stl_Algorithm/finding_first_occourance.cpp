/* This stl algo is used to find the first occourance of a element in the iterable container

Note: return the itertor if exist else to the end() iterator 
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Syntax:
    // find(begin_itertor, end_iterator, x);
    int index, res,n;
    int arr[] = {5, 3, 6, 9, 10, 25, 3};
    vector<int> vec = {5, 2,2,2, 6, 9, 10, 4, 3};
    n=sizeof(arr)/sizeof(int);

    // in array's
    auto it  = find(arr, arr + 7,9);
    index=it-arr;
    if(index==n)
        cout<<"element do not exist"<<endl;
    else
        cout<<"element found at the index: "<<index<<endl;


    // For Vector
    auto ptr  = find(vec.begin(), vec.end(),2);
    index=ptr-vec.begin();
    if(index==n)
        cout<<"element do not exist"<<endl;
    else
        cout<<"element found at the index: "<<index<<endl;

    return 0;
}