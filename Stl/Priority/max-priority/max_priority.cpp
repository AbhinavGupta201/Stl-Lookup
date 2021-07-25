/* 
max priority queue : are the max heap 
Priority:
1. Max element remain at the top of the head 
2. Time -Complexity : O(logN)
3. Store in decesing order

Header file: queue
 */
#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Syntax: priority_queue<T>pq;
    priority_queue<int>pq; // create a empty priority_queue

    // size(): return the size of the pririty queue
    cout<<"size is: "<<pq.size()<<endl;

    // push(x): insert the x into the priority_queue
    pq.push(3);
    pq.push(1);

    // emplace(): insert the x into the priority_queue
    pq.emplace(4);
    pq.emplace(6);

    // top(): return the top of the priority_queue(maximum element )
    cout<<"top: "<<pq.top()<<endl;

    // pop() : remove the top of the pq;
    pq.pop();
    cout<<"top: "<<pq.top()<<endl;

    // empty(): return boolean (true if the pq is empty)
    cout<<"is empty: "<<pq.empty()<<endl;

    // iteration 
    while(pq.empty()!=true){
        cout<<pq.top()<<" ";
        pq.pop();
    }


    return 0;
}