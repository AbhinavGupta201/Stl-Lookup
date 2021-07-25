/* 
Unordered set is similar to the set only do not contain in any order 
Property :
1. Unique elements
2. No order 
3. Time-Complexity :
O(1) in avg case
O(n) in worst case
4. All function of the set is also availabel here also 
Header file: unordered_set

*/

/*
 RULE OF THUMB: ALWAYS USE UNORDERD_SET OVER THE SET SINCE IT'S AVG TIME COMPLEXITY IS CONSTANT IF YOU DO NOT REQURIED ELEMENTS TO BE SORTED. IF YOU GET THE TLE(TIME LIMIT EXCEED) THEN SWITCH TO THE SET.
*/
#include<unordered_set>
#include<iostream>
using namespace std;

int main()
{
    // initilisation
    unordered_set<int>st;
    // inset()
    st.insert(1);
    st.insert(20);
    st.insert(3);

    // emplace() to insert also 
    st.emplace(23);
    st.emplace(24);

    // size()
    cout<<st.size()<<endl;


    // find(key): return the iterator pointing to the element 
    auto it=st.find(3030);
    if(it==st.end())
        cout<<"element not fount \n";
    else 
        cout<<"element is present\n";
    
    // erase(key) : eraser the key if present 
    st.erase(20);

    // iteration 
    for(auto it:st)
    {
        cout<<it<<" ";
    }
    

    // clear() : clear all the element 
    st.clear();


}