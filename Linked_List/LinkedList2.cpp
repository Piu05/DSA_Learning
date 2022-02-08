//Continued functions of linked list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first=NULL;
void create(int A[],int n)
{
    Node *t,*last;
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
int main()
{
    int A[]={3,5,7,20,15};
    int x,index;
    create(A,5);
    cout<<"Enter element and postion you want to insert: ";
    cin>>x>>index;
    Insert(first,index,x);
    display(first);
    return 0;
}