/* 
Stack : linear data structure in which insertion and deletion are done at the one end, called the top of the stack 
Operation: Push(x): push the element at the top of the stack 
Pop(): remove the element at the top of the stack (Note: Don't return )
top(): return the element at the top of the stack 
 
2. Linked List Implementation
 */#include<iostream>
#include<algorithm>
using namespace std;

// change your item as per the need by default it is int here
typedef int item;

// node for the data structure
struct node{
    // data storage unit 
    item data;
    node *next;
    // constructors
    node(){
        data=0;
        next=NULL;
    }

    node(int x){
        data=x;
        next=NULL;
    }

    node(int x, node *next){
        data=x;
        next=next;
    }
};

// Stack
struct Stack
{
    node *start=NULL;

    // empty function which will return true if the linked list is empty 
    bool empty(){
        return start==NULL;
    }

    // top item: if not empty then return the item else NULL 
    item top(){
        return start? start->data : -1;
    }

    // push: will push the element at the top of the stack 
    void push(item data){
        node *n=new node(data);
        if(start==NULL){
            start=n;
            return ;
        }
        n->next=start;
        start=n;

    }

    // pop(): delete top of the stack 
    void pop(){
        if(start==NULL)
        {
            cout<<"Underflow\n";
            return ;
        }
        node *t;
        t=start;
        start=start->next;
        free(t);
    }   

    // size function which will return the number of element in the Stack
    int size(){
        node *t;
        t=start;
        int count=0;
        while (t!=NULL)
        {
            t=t->next;
            count++;
        }
        return count;   
    }

   
};

int main(){
   int cap, i, j, v;
    cap = 2;
    Stack st;
    cout << st.size() << endl;
    cout << st.empty() << endl;
    st.push(1);
    cout << (st.top()) << endl;
    st.push(3);
    cout << st.top() << endl;
    st.push(4);
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty();
    st.pop();
    st.pop();
    st.pop();
    cout << st.size() << endl;
    cout << "empty: "<<st.empty();
    return 0;
}