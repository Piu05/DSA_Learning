//Continued functions of linked list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*last,*first=NULL;
void create(int A[],int n)
{
    Node *t;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
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
}
int count(Node *p)
{
    int c=0;
    while(p!=0)
    {
        c++;
        p=p->next;
    }
    return (c);
}
//Inserting a node anywhere in linked list
void Insert(Node *p, int pos, int x)
{
    Node *t;
    if(pos<0 && pos>count(p))
        return;
    t=new Node;
    t->data=x;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
//Insert element in last
void InsertLast(int x)
{
    Node *t;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=last=t;
    else
    {
        last->next=t;
        last=t;
    }
}
//Insert element in sorted list
void SortedInsert(Node *p,int x)
{
    Node *t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}
int main()
{
    int A[]={3,5,7,10,15};
    int x,index;
    create(A,5);
    cout<<"Enter element and postion you want to insert: ";
    cin>>x>>index;
    Insert(first,index,x);
    SortedInsert(first,12);
    InsertLast(20);
    display(first);
    return 0;
}