/*Singly Circular Linked list implementation */
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

// Circular_linked_list
struct Circular_linked_list
{
    node *last = NULL;

    // empty function which will return true if the linked list is empty
    bool empty()
    {
        return last == NULL;
    }

    // front item: if not empty then return the item else NULL
    item front()
    {
        if (last == NULL)
            return -1;
        node *temp;
        temp = last->next;
        return temp->data;
    }

    // rear item: return the rear item if exist else NULL
    item rear()
    {
        if (last == NULL)
            return -1;
        return last->data;
    }

    // insert element in the linked list
    void push_back(item data)
    {
        node *n = new node(data);
        node *t;
        t = last;
        if (t == NULL)
        {
            last = n;
            last->next = last;
            return;
        }
        n->next = last->next;
        t->next = n;
        last = n;
    }

    // push_front: will push the element in the front
    void push_front(item data)
    {
        node *n = new node(data);
        if (last == NULL)
        {
            last = n;
            last->next = last;
            return;
        }
        n->next = last->next;
        last->next = n;
    }

    // pop_front(): delete the first element of the linked list
    void pop_front()
    {
        if (last == NULL)
            return;
        node *t;
        t = last->next;
        if (last->next == last)
            last = NULL;
        else
        {
            last->next = last->next->next;
        }
        free(t);
    }

    // pop_back(): delete the last element of the linked list
    void pop_back()
    {
        if (last == NULL)
            return;
        node *t, *temp;
        temp = last;
        t = last;
        if (last->next == last)
        {
            last = NULL;
        }
        else
        {
            do
            {
                t = t->next;
            } while (t->next != last);
            t->next = last->next;
            last = t;
        }
        free(temp);
    }

    // search if the element is present or not
    bool search(int data)
    {
        if (last == NULL)
            return false;
        node *t;
        t = last;
        do
        {
            if (t->data == data)
                return true;
            t = t->next;
        } while (t != last);
        return false;
    }

    // return the position of the data (first if exist multiple)
    node *find(int data)
    {
        if (search(data))
        {
            node *t;
            t = last;
            do
            {
                if (t->data == data)
                    return t;
                t = t->next;
            } while (t != last);
        }
        return NULL;
    }

    // size function which will return the number of element in the linked list
    int size()
    {
        node *t;
        t = last;
        int count = 0;
        if (last == NULL)
            return 0;
        do
        {
            count++;
            t = t->next;
        } while (t != last);
        return count;
    }

    // print: print the element of the linked list
    void print_list()
    {
        node *t;
        t = last;
        if (last == NULL)
            return;
        t = t->next;
        do
        {
            cout << t->data << " ";
            t = t->next;
        } while (t != last->next);
        cout << endl;
    }
};

int main()
{
    int n, i, j, k;
    Circular_linked_list ll;
    cout << ll.size() << endl;
    ll.push_back(1);
    ll.push_back(12);
    ll.push_back(4);
    ll.push_front(10);
    ll.print_list();
    cout << endl;
    cout << ll.search(12) << endl;
    node *t = ll.find(12);

    ll.pop_back();
    ll.pop_front();
    ll.print_list();
    cout << ll.empty() << endl;
    cout << ll.front() << endl;
    cout << ll.rear() << endl;
    cout << ll.size() << endl;
    return 0;
}