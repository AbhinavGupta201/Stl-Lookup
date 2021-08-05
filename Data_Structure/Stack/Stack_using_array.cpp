/* 
Stack : linear data structure in which insertion and deletion are done at the one end, called the top of the stack 
Operation: Push(x): push the element at the top of the stack 
Pop(): remove the element at the top of the stack (Note: Don't return )
top(): return the element at the top of the stack 
 
1. Array Implementation
 */
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// by default it is int here! change accordingly
typedef int item;

// Stack Implementation
struct Stack
{
    int top;
    int capacity;
    item *array;

    // constructor : to set the capacity of the stack
    Stack(int cap)
    {
        top = -1;
        capacity = cap;
        array = (item *)malloc(sizeof(item) * cap);
    }

    // top: return the top element of the stack
    item at_top()
    {
        if (top == -1)
            return -1;
        return array[top];
    }

    // push : push the element at the top of the stack if it is not a overflow
    void push(item x)
    {
        if (top == capacity - 1)
        {
            cout << "Overflow\n";
            return;
        }
        top++;
        array[top] = x;
    }

    // pop(): remove the top element of the stack, if it is not a underflow condition
    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow \n";
            return;
        }
        top--;
    }

    // empty(): return boolean , true if stack is empty
    bool empty()
    {
        return (top == -1);
    }

    // full(): return true if the stack is full
    bool full()
    {
        return (top == capacity - 1);
    }

    // size(): return the number of element in the stack
    int size()
    {
        return (top + 1);
    }
};

int main()
{
    int cap, i, j, v;
    cap = 2;
    Stack *st = new Stack(cap);
    cout << st->size() << endl;
    cout << st->empty() << endl;
    cout << st->full() << endl;
    st->push(1);
    cout << (st->at_top()) << endl;
    st->push(3);
    cout << st->at_top() << endl;
    st->push(4);
    cout << st->at_top() << endl;
    cout << st->size() << endl;
    cout << st->full() << endl;
    cout << st->empty();
    st->pop();
    st->pop();
    st->pop();
    cout << st->size() << endl;
    cout << st->full() << endl;
    cout << "empty: "<<st->empty();
    return 0;
}
