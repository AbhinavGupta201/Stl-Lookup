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
    Heap()
    {
        size = 0;
        capacity = 1;
        arr = (item *)realloc(arr, (sizeof(item) * capacity));
    }

    // push the element in the heap
    // Time -Complexity : O(logN)
    void push(int data)
    {
        if (size == capacity)
        {
            capacity *= 2;
            arr = (item *)realloc(arr, (sizeof(item) * capacity));
        }
        arr[size] = data;
        size++;
        int par;
        int i = size - 1;
        par = (i - 1) / 2;
        while (arr[par] < arr[i] && i != 0)
        {
            swap(arr[par], arr[i]);
            i = par;
        }
    }

    // top(): return the top of the heap
    // Time-complexity : O(1);
    item top()
    {
        if (size == 0)
            return -1;
        return arr[0];
    }

    // pop(): delete the root of the node always also can be seen as extract operation
    void pop()
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
            int temp = i;
            if (2 * i + 1 < size)
            {
                if (arr[temp] < arr[2 * i + 1])
                    temp = 2 * i + 1;
            }
            if (2 * i + 2 < size)
            {
                if (arr[temp] < arr[2 * i + 2])
                    temp = 2 * i + 2;
            }
            if (temp == i)
                break;
            swap(arr[i], arr[temp]);
            i = temp;
        }
    }
    //given the index of the heap array where it is not following the heap property. this opeation fix the heap
    void heapify(int i)
    {
        int i, left, right;
        while(i<size){
            int res=i;
            if(2*i+1<size && arr[2*i+1]>arr[res])
                res=2*i+1;
            if(2*i+2<size && arr[2*i+2]>arr[res])
                res=2*i+2;
            if(res==i)
                break;
            swap(arr[i],arr[res]);
            i=res;
        }
    }

    // increase_key(int i, int v): this operation increases the value at the index i of the array to the v
    // only way of avoiding the heap property is on the top side since the value is increased
    void increase_key(int i, int v){
        arr[i]=v;
        while (i!=0 && arr[(i-1)/2]<arr[i])
        {
            swap(arr[i], arr[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    // delete(int i): this operation basically delete the ith node
    // use the increasekey to make it's value maximum so that it reaches to the top and then by calling the extract min we will extract it.
    void delete_key(int i){
        increase_key(i, 1000000007);
        pop();
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
};

int main()
{
    Heap *hp = new Heap();
    hp->push(10);
    hp->push(1);
    hp->push(3);
    hp->push(5);
    hp->push(2);
    hp->push(6);
    hp->push(4);
    cout << "size: " << hp->size << endl;
    cout << "empty: " << hp->empty() << endl;
    hp->print();
    cout << hp->top() << endl;
    hp->pop();
    hp->print();
    cout << "size: " << hp->size << endl;
    cout << "empty: " << hp->empty() << endl;
    return 0;
}