/*Singly Linked list implementation */
#include<iostream>
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

// linked_list
struct linked_list
{
    node *start=NULL;

    // empty function which will return true if the linked list is empty 
    bool empty(){
        return start==NULL;
    }

    // front item: if not empty then return the item else NULL 
    item front(){
        return start? start->data : -1;
    }
    
    // rear item: return the rear item if exist else NULL
    item rear(){
        if(start==NULL)
            return -1;
        node *t;
        t=start;
        while(t->next!=NULL){
            t=t->next;
        }
        return t->data;
    }

    // insert element in the linked list
    void push_back(item data){
        node *n=new node(data);
        node *t;
        t=start;
        if(t==NULL){
            start=n;
            return ;
        }
        while (t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;
    }

    // push_front: will push the element in the front
    void push_front(item data){
        node *n=new node(data);
        if(start==NULL){
            start=n;
            return ;
        }
        n->next=start;
        start=n;

    }

    // pop_front(): delete the first element of the linked list
    void pop_front(){
        if(start==NULL)
            return ;
        node *t;
        t=start;
        start=start->next;
        free(t);
    }

    // pop_back(): delete the last element of the linked list
    void pop_back(){
        if(start==NULL)
            return ;
        if(start->next==NULL){
            node *t;
            t=start;
            start=start->next;
            free(t);
            return ;
        }
        node *t,*temp;
        t=start;
        while (t->next->next!=NULL)
        {
            t=t->next;
        }
        temp=t->next;
        t->next=NULL;
        free(temp);        
    }

    // search if the element is present or not 
    bool search(int data){
        if(start==NULL)
            return false;
        node *t;
        t=start;
        while (t!=NULL)
        {
            if(t->data==data)
                return true;
            t=t->next;
        }
        return false;
    }

    // return the position of the data (first if exist multiple)
    node* find(int data){
        if(search(data)){
            node *t;
            t=start;
            while(t->data!=data){
                t=t->next;
            }
            return t;
        }
        else
            return NULL;
    }

    // size function which will return the number of element in the linked list 
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

    // print: print the element of the linked list
    void print_list(){
        node *t;
        t=start;
        while (t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    int n,i,j,k;
    linked_list ll;
    cout<<ll.size()<<endl;
    ll.push_back(1);
    ll.push_back(12);
    ll.push_back(4);
    ll.print_list();
    cout<<endl;
    cout<<ll.empty()<<endl;
    cout<<ll.front()<<endl;
    cout<<ll.rear()<<endl;
    cout<<ll.size()<<endl;
    return 0;
}