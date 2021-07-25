/* List is similar to the Deque 
Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick. Normally, when we say a List, we talk about doubly linked list

Note : all function of deque are available here also it has remove():: which work in O(1)  time 

Header file: list
*/ 

#include<iostream>
#include<list>
using namespace std;

int main(){
    // Syntax: list<T>ls;
    list<int>ls; // empty deque

    // push_front(): push to the front
    ls.push_front(10);
    ls.push_front(20);
    ls.push_front(30);

    // emplace_front(): push to the front 
    ls.emplace_front(20);

    // push_back(): push to the end 
    ls.push_back(40);
    ls.push_back(50);

    // emplace_back(): push to the end
    ls.emplace_back(100);

    // front(): return the first element 
    cout<<"front: "<<ls.front()<<endl;

    // back(): return the back element
    cout<<"back: "<<ls.back()<<endl;

    // size(): return the size deque
    cout<<"size: "<<ls.size()<<endl;

    // empty(): return boolean (true if empty)
    cout<<"is empty: "<<ls.empty()<<endl;

    // note: there is no at(i) since it store the data at the non contigous locations

    // iterator: begin(), end(), rend(), rbegin() 
    for( auto it:ls){
        cout<<it<<" ";
    }

    // remove the all element with the value passed if present else do nothing
    ls.remove(90);
    
    // pop_front(): pop from the front
    ls.pop_front();
  
    // pop_back(): pop from the back
    ls.pop_back();

    // clear(): clear the deque
    ls.clear();

    cout<<"size is: "<<ls.size()<<endl;

    return 0;

}