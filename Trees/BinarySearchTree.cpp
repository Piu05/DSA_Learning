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
int height(Node *p)
{
    int x=0,y=0;
    if(p==0)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}
Node * RInsert(Node *p,int key)
{
    Node *t=NULL;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);
    return p;
}
Node *InPre(Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
Node *InSucc(Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
Node *Delete(Node *p,int key)
{
    Node *q=NULL;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int main()
{
    Node *temp;
    /*Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);*/
    root=RInsert(root,50);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,30);
    Delete(root,30);
    inorder(root);
    temp=Search(2);
    if(temp!=NULL)
        cout<<"\nElement "<<temp->data<<" found";
    else
        cout<<"\nElement not found";
    return 0;

}