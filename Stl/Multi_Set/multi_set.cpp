/* 
Multi set is also a set in which elements are sorted in ascending order but it store all occourance of the element

Property:
1. Store all the element (not unique)
2. Time Complexity: O(logN) in all cases
3. All funcion of the set is here present

Header File: multiset
*/
#include <set>
#include <iostream>
using namespace std;

int main()
{
    // syntax: multiset<int>ms; {} set
    multiset<int> ms; // {}

    // 1. insert() or emplace() : to insert
    ms.insert(3);
    ms.emplace(1);
    ms.insert(3);
    ms.emplace(1);
    ms.insert(2);
    ms.emplace(3);

    // size(): give the size of the set
    cout << ms.size() << endl;

    // count(key): give the count of occourance of the key
    cout << "count of 3is:" << ms.count(3) << endl;

    // iteration
    for (auto it : ms)
    {
        cout << it << " ";
    }

    // erase(key): delete all instances of key
    ms.erase(3);
    cout<<endl;
    for (auto it : ms)
    {
        cout << it << " ";
    }

    // find(key): return the first occourance iteraro else to the end()
    auto it=ms.find(3);
    if(it==ms.end()) 
        cout<<"element not exist"<<endl;
    else
        cout<<"element is :"<<*it<<endl;

    return 0;
}
