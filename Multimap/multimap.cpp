/* Multimap is similar to the map but,

Property:
1. Key need not be unique(many value to one key is possible)
2. But value corresponding to same key should be different 
3. Sorted in Dictionary Order

Time-Complexity: O(logN) in all cases

*/

#include<map>
#include<iostream>
using namespace std;

int main(){
    // Syntax: map<T,T> mp;
    multimap<string, int>mp; // empty map
    
    // []:using this you can't inset for that their is insert(pair<T, T >( key, value)): function 
    mp.insert(pair<string,int> ("raj",20));
    mp.insert(pair<string,int> ("abhinav",32));
    mp.insert(pair<string,int>  ("shyam",19));

    // new value to the existing key will be modified 
    // emplace(key, value): will also insert the key value pair 
    mp.emplace("raj",29);
    mp.emplace("shyam",31);

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

    // find(key):return the first occourance iterator if exist else to the end() iterator
    // Note: it return the iterator to pair so to access the key and value use the -> operator 
    // i.e. it->first and it->second
    auto it =mp.find("abhinav");
    if(it==mp.end())
        cout<<"key doesn' exist "<<endl;
    else
        cout<<"key found & value is: "<<it->first<<" :"<<it->second<<endl;
    
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