/* Tree is a hierarchical data structure and store the parent child relationship 
Property:
1. it's acyclic.
2. For n vertex there is n-1 edges
3. There is unique path between the two point u and v. 

Difination: A tree is a non linear data structure in which there is a special node called root node and it's children's can be divided into n>=0 number of disjoint ordered set.

Types :
1. Binary Tree: there will be atmost two childs for each node 
2. General Tree : can have any number of childs

Binary Search Tree: has a property apart from being binary tree is : the value in left child is less than the root , while the right child value is greater than root.

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// here item is int datatype. Change it accordingly 
typedef int item;

// node for the BST
struct node
{
    // Data storage
    item data;
    node *left;
    node *right;
    
    // constructor
    node(int x, node *l=NULL, node *r=NULL){
        data=x;
        left=l;
        right=r;
    }
};

struct BST
{
    node *root=NULL; // root of the node

    // insert function 
    void insert(int x){
        node *n=new node(x);
        if(root==NULL)
        {
            root=n;
            return ;
        }
        node *temp;
        temp=root;
        while(temp){
            if(x < temp->data){
                if(temp->left==NULL)
                    temp->left=n;
                temp=temp->left;
            }
            else if(x > temp->data){
                if(temp->right==NULL)
                    temp->right=n;
                temp=temp->right;
            }
            else 
                return ;
        }
    }

    // find(): return the reference to the position else NULL
    node* find(node *root,int x){
        if(root){
            if(root->data<x)
                return find(root->right,x);
            else if(root->data>x)
                return find(root->left,x);
            else 
                return root;
            
        }
        return NULL;
    }

    node* find(int data){
        return find(root, data);
    }

    // preorder traversal
    void preorder(node *root){
        if(root){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Inorder traversal
    void inorder(node *root){
        if(root){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    // postorder traversal
    void postorder(node *root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

    // level order traversal 
    void levelorder(node *root){
        queue<node*>q;
        if(root!=NULL)
            q.push(root);
        while (q.size()!=0)
        {
            root=q.front();
            q.pop();
            cout<<root->data<<" ";
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        
    }

    void preorder(){
        preorder(root);
    }

    void postorder(){
        postorder(root);
    }

    void inorder(){
        inorder(root);
    }

    void levelorder(){
        levelorder(root);
    }

    // delete the node
    node* delete_node(node *root, int x){
        if(root->data > x){
            root->left=delete_node(root->left,x);
        }
        else if(root->data < x){
            root->right=delete_node(root->right,x);
        }
        else{
            // element is found to be deleted 
            if(root->left==NULL && root->right==NULL)
            {
                return NULL;
            }
            if(root->left==NULL )
            {
                node *temp;
                temp=root->right;
                while(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                x=temp->data;
                root->data=x;
                root->right=delete_node(root->right,x);
            }
            if(root->right==NULL)
            {
                node *temp;
                temp=root->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                x=temp->data;
                root->data=x;
                root->left=delete_node(root->left,x);
            }
        }
        return root;
    }

    void delete_node(int x){
        root=delete_node(root,x);
    }

};

int main(){
    BST bt;
    bt.insert(50);
    bt.insert(10);
    bt.insert(5);
    bt.insert(34);
    bt.insert(1);
    bt.inorder();
    cout<<endl;
    bt.preorder();
    cout<<endl;
    bt.postorder();
    cout<<endl;
    bt.levelorder();
    cout<<endl;
    node *t;
    t=bt.find(24);
    if(t==NULL)
        cout<<"element is not found\n";
    else
        cout<<"found\n";

    t=bt.find(1);
    if(t==NULL)
        cout<<"element is not found\n";
    else
        cout<<"found\n";
    bt.inorder();
    cout<<endl;
    bt.delete_node(50);
    bt.inorder();
    return 0;
}