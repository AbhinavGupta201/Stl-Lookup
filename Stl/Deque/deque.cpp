/* Deque : is a stl for doubly ended queue

Property:
1. It's double ended queue
2. Header file: deque

*/
#include<iostream>
#include<deque>
using namespace std;

int main(){
    // Syntax: deque<T>dq;
    deque<int>dq; // empty deque

    // push_front(): push to the front
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);

    // emplace_front(): push to the front 
    dq.emplace_front(20);

    // push_back(): push to the end 
    dq.push_back(40);
    dq.push_back(50);

    // emplace_back(): push to the end
    dq.emplace_back(100);

    // front(): return the first element 
    cout<<"front: "<<dq.front()<<endl;

    // back(): return the back element
    cout<<"back: "<<dq.back()<<endl;

    // size(): return the size deque
    cout<<"size: "<<dq.size()<<endl;

    // empty(): return boolean (true if empty)
    cout<<"is empty: "<<dq.empty()<<endl;

    // at(i): return element at index i
    cout<<"at index 3: "<<dq.at(3)<<endl;

    // iterator: begin(), end(), rend(), rbegin() 
    for( auto it:dq){
        cout<<it<<" ";
    }

    // pop_front(): pop from the front
    dq.pop_front();
  
    // pop_back(): pop from the back
    dq.pop_back();

    // clear(): clear the deque
    dq.clear();

    cout<<"size is: "<<dq.size()<<endl;

    return 0;







}