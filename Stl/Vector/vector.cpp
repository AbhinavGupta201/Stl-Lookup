/* vector is just like array but dynamic in nature
Header file: vector
*/
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    /* Syntax: vector< T > name; :: declear the vector with empty size
    */
    /* --------initilisation---------- */
    vector<int> arr;        //{}
    vector<int> arr1(3);    // will create a size of 3 All 0's
    vector<int> arr2(3, 2); // size 3 and all with the 2
    int myarr[] = {12, 3, 4, 5, 6};
    vector<int> arr4(myarr, myarr + 5);               // [begin , end ) to creat from other array
    vector<int> arr5(arr1.begin(), arr1.begin() + 2); // first 2 elements are copied
    vector<int> arr6(arr2);                           // all elements are copied in the arr6

    cout << "arr1 size: " << arr1.size() << endl;
    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";

    cout << "arr2 size: " << arr2.size() << endl;
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << " ";

    //1. size(): give the vector
    cout << "Size: " << arr.size() << endl; // 0

    //2. push_back() : insert the element at the end
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    cout << "Size: " << arr.size() << endl; // 1
    cout << "array is: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    //3. emplace_back() : insert the element at the end but faster than the push_back
    arr.emplace_back(1);
    arr.emplace_back(2);
    arr.emplace_back(3);
    cout << "\nSize: " << arr.size() << endl; // 1
    cout << "array is: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    //4. pop_back(): remove the last element DO NOT RETURN
    arr.pop_back();
    cout << "\nSize: " << arr.size() << endl; // 1
    cout << "array is: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    // 5. clear(): clear the vector
    arr.clear();
    cout << "\nSize: " << arr.size() << endl; // 1
    cout << "array is: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    //6. capacity(): to hold number of elements it don't decrease with the decrese in size
    cout << "capacity is : " << arr.capacity() << endl;

    /* 2D and 3D vectors  */
    vector< vector<int> >arr7; // { { }} 
    vector< vector<int> >arr8(10,vector<int>(20,0)); // 10*20 and each row 0
    cout<<"arr8 is:\n";
    for(auto it:arr8){
        for(auto jt: it)
            cout<<jt<<" ";
        cout<<endl;
    }  
    vector<  vector< vector<int> >>arr3d; // { { {}}}
    cout<<"arr 7 size: "<<arr7.size()<<endl;

    // 8. can also use the at(): to access the elements at the index
    cout<<arr4.at(0);
}