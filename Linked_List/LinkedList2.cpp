//Continued functions of linked list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*last,*first=NULL,*second=NULL;
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
    cout<<endl;
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
int Delete(Node *p,int pos)
{
    Node *q=NULL;
    int x=-1;
    if(pos<1 || pos>count(first))
    {
        return -1;
    }
    if(pos==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}
//Check if list is sorted
int CheckSort(Node *p)
{
    int x=INT32_MIN;
    while(p)
    {
        if(p->data<x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}
//Remove duplicates from sorted list
void RemoveDup(Node *p)
{
    Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
//Concatenate 2 lists
void create2(int A[],int n)
{
    Node *t;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Concat(Node *p,Node *q)
{
    Node *third;
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    display(third);
}
int main()
{
    int A[]={3,5,5,10,20};
    int x,index;
    create(A,5);
    cout<<"Enter element and postion you want to insert: ";
    cin>>x>>index;
    Insert(first,index,x);
    SortedInsert(first,12);
    InsertLast(20);
    display(first);
    Delete(first,4);
    display(first);
    if(CheckSort(first))
        cout<<"List is sorted\n";
    else
        cout<<"List is not sorted\n";
    RemoveDup(first);
    display(first);
    int B[]={10,20,30,40};
    create2(B,4);
    cout<<"\nSecond list: ";
    display(second);
    Concat(first,second);
    return 0;
}