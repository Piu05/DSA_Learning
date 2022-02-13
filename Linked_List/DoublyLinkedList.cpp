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
int main()
{   
    int A[]={1,3,5,7,9};
    create(A,5);
    display(first);
    cout<<"\nLength: "<<length(first);
    return 0;
}
