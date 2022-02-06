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
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    display(first);
    cout<<endl;
    Display(first);
    return 0;
}