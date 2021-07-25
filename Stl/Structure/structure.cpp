#include<iostream>
using namespace std;

// these are called the user defined datatypes 
/* 
// in cpp: 
// In cpp: the use of struct before the datatypes is completely optional 
1. can have member variable as well as function 
1. it can be as the class with the struct name 
*/
struct Node{
    int a;
    int b;
    string name;
    Node(int a_,int b_,string name_)
    {
        a=a_;
        b=b_;
        name=name_;
    }
};
// using typedef to rename the structure 

typedef struct{
    int a;
    float b;
}Person;


int main()
{
    // cout<<p1.a<<p1.b<<p1.name<<endl;
    // Person p1;

    // ways of initilising the structure 
    // p1.a=20;
    // p1.b=30;

    // Person p2={1,2.3};
    Node *p2=new Node(1,2,"abhishek");
    cout<<p2->a<<" "<<p2->b<<" "<<p2->name<<endl;
    // 
    return 0;
}