/*
//Linked List
-It is a collection of nodes where each node contains data and the pointer to next node
-Head is a pointer pointing to first node.

*/
#include<iostream>
using namespace std;
struct Node         //Self-referential structure (structure pointing to itself) 
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
//Display using loop
void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
//Display using recursive function      //time complexity-O(n) [stack size=n+1]
void Display(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        Display(p->next);
    }
}
//Counting nodes
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
//Counting nodes using recursion
int Count(Node *p)
{
    if(p==0)
        return 0;
    else
        return Count(p->next)+1;
}
//Sum of elements 
int Add(Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;    
}
//Finding max element
int Max(Node *p)
{
    int max=INT32_MIN;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
//Method 2 using recursion
int Rmax(Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
    
}
//Searching an element
Node* Search(Node *p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}
//Searching an element using recursion
Node* RSearch(Node *p,int key)
{
    if(p==0)
        return 0;
    if (key==p->data)
        return p;
    else 
        RSearch(p->next,key);
}
//Improve search by making the searched element in front for future ease
Node * ImpSearch(Node *p, int key)
{
    Node *q=NULL;
    while(p)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
}
//Reversing a linked list   (Using array)
void Reverse1(Node *p)
{
    int *A,i=0;
    Node *q=p;
    A=new int[Count(first)];
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}
//Reversing a list by reversing links   (Using sliding pointer)
void Reverse2(Node *p)
{
    Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
//Revrsing a list using recursion
void Reverse3(Node *q,Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}
int main()
{
    int A[]={3,5,7,20,15};
    int x;
    create(A,5);
    display(first);
    cout<<endl;
    cout<<"No. of elements= "<<Count(first);
    cout<<"\nSum of elements= "<<Add(first);
    cout<<"\nMaximum element= "<<Rmax(first);
    cout<<"\nEnter the element you want to search: ";
    cin>>x;
    if(RSearch(first,x)==NULL)
        cout<<"Element not found";
    else
        cout<<"Element found at "<<RSearch(first,x);
     cout<<endl;
    cout<<ImpSearch(first,x);
    cout<<endl;
    Display(first);     //To check if element has come to front after found
    Reverse1(first);
    Reverse2(first);
    Reverse3(NULL,first);
    display(first);
    return 0;
}