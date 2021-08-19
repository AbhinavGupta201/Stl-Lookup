/* Map : is for storing the key-valur pair 
Property:
1. Stores unique key 
2. Dictionary Order
3. Time-complexity: O(logN) in all cases

Header file: map

*/
#include<map>
#include<iostream>
using namespace std;

int main(){
    // Syntax: map<T,T> mp;
    map<string,int>mp; // empty map
    
    // []:using this we can store the new value if it don't exits
    mp["raj"]=20;
    mp["abhinav"]=32;
    mp["shyam"]=19;

    // new value to the existing key will be modified 
    // emplace(): will also insert the key value pair 
    mp.emplace("ravi",29);
    mp.emplace("satyam",31);

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

}