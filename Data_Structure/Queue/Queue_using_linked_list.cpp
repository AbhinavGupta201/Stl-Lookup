/*Queue: is a linear data structure in which insertion is done at the rear end while deletion is done at the front end 
It is of type: FIFO

Linked List implementation
*/
#include <iostream>
#include <algorithm>
using namespace std;

// change your item as per the need by default it is int here
typedef int item;

// node for the data structure
struct node
{
    // data storage unit
    item data;
    node *next;
    // constructors
    node()
    {
        data = 0;
        next = NULL;
    }

    node(int x)
    {
        data = x;
        next = NULL;
    }

    node(int x, node *next)
    {
        data = x;
        next = next;
    }
};

// Queue
struct Queue
{
    node *start = NULL;

    // empty function which will return true if the Queue is empty
    bool empty()
    {
        return start == NULL;
    }

    // front item: if Queue is not empty then return the item else NULL
    item front()
    {
        return start ? start->data : -1;
    }

    // rear item: return the rear item if exist else NULL
    item rear()
    {
        if (start == NULL)
            return -1;
        node *t;
        t = start;
        while (t->next != NULL)
        {
            t = t->next;
        }
        return t->data;
    }

    // insert element in the front of the queue
    void enqueue(item data)
    {
        node *n = new node(data);
        node *t;
        t = start;
        if (t == NULL)
        {
            start = n;
            return;
        }
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;
    }

    // dequeue(): delete the first element of the queue
    void dequeue()
    {
        if (start == NULL)
        {
            cout << "underflow\n"
                 << endl;
            return;
        }
        node *t;
        t = start;
        start = start->next;
        free(t);
    }

    // size function which will return the number of element in the queue
    int size()
    {
        node *t;
        t = start;
        int count = 0;
        while (t != NULL)
        {
            t = t->next;
            count++;
        }
        return count;
    }

    // print: print the element of the queue
    void print_queue()
    {
        node *t;
        t = start;
        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{
    int n, i, j, k;
    Queue q;
    cout << q.size() << endl;
    q.enqueue(1);
    q.enqueue(12);
    q.enqueue(4);
    q.print_queue();
    cout << endl;
    q.dequeue();
    cout << q.empty() << endl;
    cout << q.front() << endl;
    cout << q.rear() << endl;
    cout << q.size() << endl;
    return 0;
}