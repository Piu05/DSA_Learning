//Doubly Linked List
/*
-It contains data and 2 pointers 
-One pointer points to previous node and other to next node
*/
#include<iostream>
using namespace std;
struct Node
{
    Node *prev;
    int data;
    Node *next;
}*first=NULL;
Node* CreateNode(int x)
{
    Node *t=new Node;
    t->data=x;
    t->prev=NULL;
    t->next=NULL;
    return t;
}
void create(int A[],int n)
{
    Node *t,*last;
    int i;
    first=CreateNode(A[0]);
    last=first;
    for(i=1;i<n;i++)
    {
        t=CreateNode(A[i]);
        t->prev=last;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(Node *p)         
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int length(Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void Insert(Node *p,int pos,int x)
{
    Node *t;
    int i;
    if(pos<0 || pos>length(p))
        return;
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(i=0;i<pos-1;i++)
            p=p->next;
        t=new Node;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}
void Reverse(Node *p)
{
    Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}
int Delete(Node *p,int pos)
{
    Node *q;
    int x=-1,i;
    if(pos<1 || pos>length(p))
        return -1;
    if(pos==1)
    {
        first=first->next;
        if(first)   first->prev=NULL;
        x=p->data;
        delete p;
    }
    else
    {
        for(i=0;i<pos-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}
int main()
{   
    int A[]={1,3,5,7,9};
    create(A,5);
    display(first);
    cout<<"\nLength: "<<length(first)<<endl;
    Insert(first,2,25);
    display(first);
    Reverse(first);
    display(first);
    Delete(first,4);
    display(first);
    return 0;
}
//Other linked list functions will be same as singly linked list only the node positions will be different
//Circular Doubly linked list
/*
If we want to add new node before head node then we can just go to last node bu using head->prev
It can be done in constant time without traversing to whole list
Should write program for insertion and deletion in circular doubly linked list as practice
*/