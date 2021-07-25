/* Queue is a FIFO kind of data structure
Note: 
1. There is no iterator here & no clear funcion 
2. Time -Complexity: O(1) in all cases

Header file: queue
*/
#include<queue>
#include<iostream>
using namespace std;

int main(){
    // Syntax: queue<T>q;
    queue<int>q; // empty queue of size 0;

    // size(): return the number of element in the queue
    cout<<"size is: "<<q.size()<<endl;

    // push(x): push the element at the end of the queue  
    q.push(9);
    q.push(2);
    q.push(1);
    q.push(5);

    // emplace(x): similar to the push 
    q.emplace(38);
    q.emplace(39);

    //font(): return the element at the front :: give segmentation fault if there is no element  
    cout<<"front is:"<<q.front()<<endl;

    // pop(): remove an element from the front :: don't return 
    q.pop();
    cout<<"front is:"<<q.front()<<endl;
    
    // empty() : return boolean ( true if empty )
    cout<<"is empty:"<<q.empty()<<endl;

    // iteration over the queue
    cout<<"Queue is: ";
    while(q.empty()!=true){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}