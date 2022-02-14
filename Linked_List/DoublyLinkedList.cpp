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
void create(int A[],int n)
{
    Node *t,*last;
    int i;
    first=new Node;
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->prev=last;
        t->next=NULL;
        last=t;
    }
}
void display(Node *p)           //Error
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
///////////
void Insert(Node *p,int n,int x)
{
    Node *t,*last;
    int i;
    first=new Node;
    first->data=n;
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=x;
        t->prev=last;
        t->next=NULL;
        last=t;
    }
}
void Reverse(Node *p)           //Error
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
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
    cout<<"\nLength: "<<length(first);
    Insert(first,2,25);
    Reverse(first);
    display(first);
    Delete(first,1);
    display(first);
    return 0;
}
