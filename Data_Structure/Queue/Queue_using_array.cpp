/*Queue: is a linear data structure in which insertion is done at the rear end while deletion is done at the front end 
It is of type: FIFO

Linked List implementation
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef int item;

struct Queue
{
    // data storage unit
    int front;
    int rear;
    int capacity;
    item *array;

    // constructor
    Queue(int cap)
    {
        front = -1;
        rear = -1;
        capacity = cap;
        array = (item *)malloc(sizeof(item) * cap);
    }

    // size: return the number of the element in the queue
    int size()
    {
        if (front == -1)
            return 0;
        if (front == rear)
            return 1;
        return ((capacity + rear - front + 1) % (capacity));
    }

    // full(): return true if the queue is full
    bool full()
    {
        return ((rear + 1) % capacity == front);
    }

    // empty(): return true if the queue is empty
    bool empty()
    {
        return (front == -1);
    }

    // enqueue: will enqueue the element at the rear of the queue
    void enqueue(int data)
    {
        if (full())
        {
            cout << "queue is full\n";
            return;
        }
        rear++;
        array[rear] = data;
        if (front == -1)
            front++;
    }

    // dequeue: remove front element of the queue
    void dequeue()
    {
        if (front == -1)
        {
            cout << "queue is empty: \n";
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % capacity;
    }

    // front(): return the front of the queue, else -1
    item at_front()
    {
        if (front == -1)
        {
            cout << "Queue is empty: \n";
            return -1;
        }
        return array[front];
    }

    // rear(): will return the element at the rear of the queue
    item at_rear()
    {
        if (front == -1)
        {
            cout << "Queue is empty: \n";
            return -1;
        }
        return array[rear];
    }

    // print_queue: will print the queue
    void print_queue()
    {
        int i;
        i = front;
        if (front == -1)
            return;
        do
        {
            cout << array[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % (capacity));
    }
};

int main()
{
    int n, i, j, k;
    Queue *Q = new Queue(3);
    Queue q = *Q;
    cout << q.size() << endl;
    q.enqueue(1);
    q.enqueue(12);
    q.enqueue(4);
    q.enqueue(40);
    q.print_queue();
    cout << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.empty() << endl;
    cout << q.at_front() << endl;
    cout << q.at_rear() << endl;
    cout << q.size() << endl;
    return 0;
}