/* set is the stl used to store the unique value only :it is implemented as red-black Tree in backend
Property:
1. Store the unique value
2. Store in ascending order 
3. time complexity: O(logN) :: in all cases
4. Since it is ascendin order so it is ordered 
Header file: set
 */
#include <set>
#include <iostream>
using namespace std;

int main()
{
    /* Syntax: set<T>st; */
    // declearation
    set<int> st;                                   // empty set {}
    set<int> st1 = {1, 2, 3, 4, 2, 2, 3, 3, 2, 1}; // initilse with the unique value only

    // 1.insert(): insert value to the set if already present then no else yes
    st.insert(1);
    st.insert(2);
    st.insert(1);
    st.insert(3);
    st.insert(20);
    st.insert(10);
    st.insert(30);

    // 2.[] : operator is not applicable here to access
    // to access the element we have to use the iterator

    cout << "set is: ";
    for (auto it : st)
    {
        cout << it << " ";
    }

    // 3i. erase(iterator): erase the element pointed by the iterator
    st.erase(st.begin());
    cout << "\nset is: ";
    for (auto it : st)
    {
        cout << it << " ";
    }
    // 3ii. erase(key): key to be deleted if present then delete else nothing
    st.erase(5);
    for (auto it : st)
    {
        cout << it << " ";
    }
    // 3iii. erase(begin_it, end_it): remove all the element from begin [before end)
    // auto end=st.begin()+3;
    // st.erase(st.begin(),end);

    // 4.find(key): return the iterator if key is present else return st.end()
    auto it = st.find(20);
    cout << endl;
    if (it == st.end())
        cout << "element do not exist " << endl;
    else
        cout << *it << endl;

    // 5. size(): return the number of element if the set
    cout << "size is: " << st.size() << endl;

    // 6. emplace(): insert only buy faster then insert
    st.insert(202);
    cout << "\nset is: ";
    for (auto it : st)
    {
        cout << it << " ";
    }

    // clear() : clear all the element
    st.clear();
    cout << "size is: " << st.size() << endl;
    cout << "\nset is: ";
    for (auto it : st)
    {
        cout << it << " ";
    }
}