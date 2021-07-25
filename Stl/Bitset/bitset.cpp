/* Bitset is stl for storing the fixed size bits collection
Propery
1. Store the bits only so only 0 or 1 (1 bit)
2. Size is fixed and can't be changed later
3. Memory allocation is contigous 

Header file: bitset
 */
#include<iostream>
#include<bitset>
using namespace std;

int main(){
    // Syntax: bitset<size> bt;
    bitset<5>bt; // will create the set of 5 bits

    // input taking 
    cin>>bt;

    // all(): it return true if all the bits are 1's 
    cout<<" is all 1's :"<<bt.all()<<endl;

    // any(): return true if atleast one bit is set
    cout<<"is any set: "<<bt.any()<<endl;

    // count(): return the number of set bits
    cout<<"count of set bits: "<< bt.count()<<endl;

    // flip(i): flip the specified bit index 
    bt.flip(3);

    // none(): return true if the none of the bit is set
    cout<<"none is set: "<<bt.none()<<endl;

    // set(): set all bit position 
    bt.set(); //set all bit position 
    cout<<"count: "<<bt.count()<<endl;

    // set(i): set the index ith (to 1)
    bt.set(2);

    // set(i,0): set the ith bit to 0 
    bt.set(2,0);

    // reset() : reset all the bits positins
    bt.reset();

    // reset(i) : reset the index i to 0
    bt.reset(2);

    // size(): number of element in the bitset
    cout<<"size is: "<<bt.size()<<endl;

    // test(i): return boolean ( true if the ith bit is set )
    cout<<"3th bit : "<<bt.test(3)<<endl;

    // iteration
    for(int i=0;i<bt.size();i++){
        cout<<bt.test(i)<<" ";
    }








}