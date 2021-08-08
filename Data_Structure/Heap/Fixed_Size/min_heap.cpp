/* 
Heap is a data structure which is a tree with some special property 
1. It't Almost Complete Binary Tree (all leafs are at the last level or last to last level )
2. Value of node is either >= to its childrens or <= to it's childrens 

There are two types of heaps
1. Min Heap : value at the node is less than or equal to its children
2. Max Heap : value at it's node is greater than or equal to its children

Min Heap implementation : 
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef int item;
struct Heap
{
    // data Structure
    int capacity;
    int size;
    item *arr;

    // constructor
    Heap(int cap)
    {
        size = 0;
        capacity = cap;
        arr = (item *)malloc(sizeof(item) * cap);
    }

    // insert the element in the heap
    // Time -Complexity : O(logN)
    void insert(int data)
    {
        if (size == capacity)
        {
            cout << "heap is full\n";
            return;
        }
        arr[size] = data;
        size++;
        int par;
        int i = size - 1;
        par = (i - 1) / 2;
        while (arr[par] > arr[i] && i != 0)
        {
            swap(arr[par], arr[i]);
            i = par;
        }
    }

    // peep(): return the top of the heap
    // Time-complexity : O(1);
    item peep()
    {
        if (size == 0)
            return -1;
        return arr[0];
    }

    // delete(): delete the root of the node
    void delete_node()
    {
        if (size == 0)
            return;
        if (size == 1)
        {
            size--;
            return;
        }
        swap(arr[0], arr[size - 1]);
        size--;
        int i = 0;
        while (i < size)
        {
            cout << "in the loop\n i=" << i << endl;
            int temp = i;
            if (2 * i + 1 < size)
            {
                if (arr[temp] > arr[2 * i + 1])
                    temp = 2 * i + 1;
            }
            if (2 * i + 2 < size)
            {
                if (arr[temp] > arr[2 * i + 2])
                    temp = 2 * i + 2;
            }
            if (temp == i)
                break;
            swap(arr[i], arr[temp]);
            i = temp;
        }
    }

    // print the heap
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // empty(): return boolean, true if the heap is empty
    bool empty()
    {
        return (size == 0);
    }

    // full(): return bool, true if the heap is full
    bool full()
    {
        return (size == capacity);
    }
};

int main()
{
    Heap *hp = new Heap(6);
    hp->insert(10);
    hp->insert(1);
    hp->insert(3);
    hp->insert(5);
    hp->insert(2);
    hp->insert(6);
    hp->insert(4);
    cout << "size: " << hp->size << endl;
    cout << "empty: " << hp->empty() << endl;
    cout << "full is : " << hp->full() << endl;
    hp->print();
    cout << hp->peep() << endl;
    hp->delete_node();
    hp->print();
    cout << "size: " << hp->size << endl;
    cout << "empty: " << hp->empty() << endl;
    cout << "full is : " << hp->full() << endl;
    return 0;
}