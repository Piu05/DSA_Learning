//Circular Linked List
#include<iostream>
using namespace std;
struct Node         //Self-referential structure (structure pointing to itself) 
{
    int data;
    Node *next;
}*Head;
void create(int A[],int n)
{
    Node *t,*last;
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(Node *h)
{
    do
    {
        cout<<h->data<<" ";
        h=h->next;
    } while (h!=Head);
    cout<<endl;
    
}
void Rdisplay(Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        cout<<h->data<<" ";
        Rdisplay(h->next);
    }
    flag=0;
}
int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    display(Head);
    Rdisplay(Head);
    return 0;
}