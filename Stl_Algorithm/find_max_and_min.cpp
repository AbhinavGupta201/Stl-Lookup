/* This stl algo is used to find the maximum element or minimum element in the iterable container

Note: return the iterator to the position
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Syntax:
    //  max_element(begin_iterator, end_iterator)
    // min_element(begin_iterator, end_iterator)
    // ** return the reference to the location**

    int arr[] = {5, 3, 6, 9, 10, 25, 3};
    vector<int> vec = {5, 2, 6, 9, 10, 4, 3};

    int max = *max_element(arr, arr + 7);
    int min = *min_element(arr, arr + 7);

    cout << "Array ->> max: " << max << " min: " << min << endl;
    max = *max_element(vec.begin(), vec.end());
    min = *min_element(vec.begin(), vec.end());
    cout << "Vector -->>> max: " << max << " min: " << min << endl;

    return 0;
}