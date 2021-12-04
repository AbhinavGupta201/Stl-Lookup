/* 
Unordered_map is similar to map but with

Property:
1. No order of storing the element (not dictionary )
2. Only Single Key is allowed(not pair)
3. Time complexity: O(1) in almost all cases except in worst case it is O(n)

Note: every syntax and function is same 
*/
#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    // Syntax: unordered_map<T,T> mp;
    unordered_map<string,int>mp; // empty map
    
    // []:using this we can store the new value if it don't exits
    // new value to the existing key will be modified 
    mp["raj"]=20;
    mp["abhinav"]=32;
    mp["shyam"]=19;

    // emplace(): will also insert the key value pair 
    mp.emplace("ravi",29);
    mp.emplace("satyam",31);

    // insert takes the pair of the element to be inserted
    mp.insert(pair<string,int>("rakesh",200));

     // iteration
    for(auto it:mp){
        // note: it will be a pair of key-value
        cout<<"key: "<<it.first<<" value: "<<it.second<<endl;
    }

    // erase(key): will erase the key if exist
    mp.erase("raj");

    // erase(iterator): using iterator
    mp.erase(mp.begin());

    cout<<"map is\n";
     // iteration
    for(auto it:mp){
        // note: it will be a pair of key-value
        cout<<"key: "<<it.first<<" value: "<<it.second<<endl;
    }

    // count(key): return the count of number of element with the key :: either 0 or 1
    cout<<"count of abhinav"<<mp.count("shyam")<<endl;
    cout<<"count of mohig"<<mp.count("mohit")<<endl;

    // // erase(begin_it, end_it): starting to just before the last iterator
    // mp.erase(mp.begin(), mp.begin()+3);

    // find(key):return the iterator if exist else to the end() iterator
    auto it =mp.find("abhinav");
    if(it!=mp.end())
        cout<<"key doesn' exist "<<endl;
    else
        cout<<"key found & value is: "<<mp["abhinav"]<<endl;
    
    // iteration
    for(auto it:mp){
        // note: it will be a pair of key-value
        cout<<"key: "<<it.first<<" value: "<<it.second<<endl;
    }

    // clear(): clear all the element of the map
    mp.clear();


    // empty(): boolean return (true if the map is empty )
    cout<<"is empty: "<<mp.empty()<<endl;

    return 0;

}