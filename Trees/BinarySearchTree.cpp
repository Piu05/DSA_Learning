//Binary Search Tree
/*
Characteristics:
-Left child is smaller and right child is greater than parent node
-No duplicate elements
-Inorder gives sorted order
-No. of BST for n nodes = 2nCn/n+1
-Representation is mostly using linked representation
*/
#include<iostream>
using namespace std;
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;
void Insert(int key)
{
    Node *t=root;
    Node *r,*p;
    if(root==NULL)
    {
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else return;
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}
void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
Node * Search(int key)
{
    Node *t=root;
    while(t)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}
int main()
{
    Node *temp;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    inorder(root);
    temp=Search(2);
    if(temp!=NULL)
        cout<<"\nElement "<<temp->data<<" found";
    else
        cout<<"\nElement not found";
    return 0;

}