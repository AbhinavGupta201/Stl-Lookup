/* Stack : is LIFO kind of data structure

Header file: stack
*/

#include<stack>
#include<iostream>

using namespace std;

int main(){
    // Syntax: stack<T>st;
    stack<int> st; //{empty size stack

    // size(): return the size of the stack
    cout<<"size is: "<<st.size()<<endl;

    // push(x): insert at element at the top of the stack 
    st.push(1);
    st.push(3);
    st.push(4);

    // emplace(): also similar to the push 
    st.emplace(39);
    st.emplace(100);

    // top(): return the element at the top :: segmentation fault if stack is empty 
    cout<<st.top()<<endl;

    // pop(): remove the top element :: don't return 
    st.pop();
    cout<<st.top()<<endl;

    // empty(): return boolean (if empty return true)
    cout<<"is empty :"<<st.empty()<<endl;


    // iteration over stack
    while(st.empty()!=true){
        cout<<st.top()<<" "<<endl;
        st.pop();
    }

    // Note: there is no iterator and clear in the stack 
    
}