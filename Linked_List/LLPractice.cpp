#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first=NULL,*second=NULL,*last;
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
//Finding middle node
int MiddleEle(Node *p)
{
    Node *q;
    q=first;
    while(q)
    {
        q=q->next;
        if(q)   q=q->next;
        if(q)   p=p->next;
    }
    return p->data;
}
//Finding Intersection of 2 linked lists
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
    second->next->next=first->next->next->next->next;
}
int Intersection(Node *p,Node *q)
{
    
    while(p!=NULL)
    {   
        while(q!=NULL)
        {    
            if(p==q)
                return p->data;
            else
                q=q->next;
        }
        q=second;
        p=p->next;
    }
}
int main()
{
    int A[]={1,2,3,4,5,6,7};
    int B[]={20,30,40};
    create(A,7);
    create2(B,3);
    cout<<"Middle element is: "<<MiddleEle(first);
    cout<<"\nIntersection element is: "<<Intersection(first,second);
    return 0;
}
