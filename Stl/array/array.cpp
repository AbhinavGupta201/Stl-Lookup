// arry are the stl which is similar to the array of the c language
// You need to include the array header to the file to use this 
#include <array>
#include <iostream>
using namespace std;
array<int, 3> glb;
int main()
{
    /* initilisation */
    // syntax: array< datatype, size > name_of_array
    array<int, 5> arr; // note: uninitilised contains the garbage value [?,?,?,?,?]
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    // global unitilised one alway inililised as the zero

    for (int i = 0; i < 3; i++)
    {
        cout << glb[i] << endl;
    }
    // array at least one member initilised contain all other uninitilised as the 0
    array<int, 5> arr2 = {1}; //[1,0,0,0,0]
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << endl;
    }

    // that is why to initilised all the elements as the zero we do
    array<int, 5> arr3 = {0}; // [0,0,0]
    arr3[0]=100;
    for (int i = 0; i < 5; i++)
    {
        cout << arr3[i] << endl;
    }

    // fill(x): fill with the x to all the elements 
    arr3.fill(15);
    for (int i = 0; i < 5; i++)
    {
        cout << arr3[i] << endl;
    }

    // at(index) : to give the value at the index
       for (int i = 0; i < 5; i++)
    {
        cout << arr3.at(i) << endl;
    }
    // size() : give the size of the array 
    cout<<"size :"<<arr3.size()<<endl;
    // front(): give the front element
    cout<<"front :"<<arr3.front()<<endl;
    // back(): give the last element
    cout<<"rear :"<<arr3.back()<<endl;

    /* Iterators */
    /* 
    1.begin(): point to the first element of the container
    2. end() : point to one after the last element of the container 
    3. rbegin(): point to the last element of the container 
    4. rend(): point to the one before the first element of the container 

    Uses: arr.begin() : return the pointer to the location 
    Note: these iterators are present in almost every container except : stack , queue 
    */

    cout<<"arr2 is:\n";
    /* using for loop */
    for(auto it=arr2.begin();it!=arr2.end();it++)
    {
        cout<<*it<<" ";
    }

    cout<<"\narr2 is:\n";
    // Note: in for each it contain the value at the position not the pointer
    // using for each loop 
    for(auto it:arr2)
    {
        cout<<it<<" ";
    }

    
} 