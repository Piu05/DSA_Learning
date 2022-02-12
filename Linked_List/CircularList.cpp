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
int Length(Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    } while (p!=Head);
    return len;
}
//Inserting a node
void Insert(Node *p,int index,int x)
{
    Node *t;
    int i=0;
    if(index<0 || index>Length(Head))
    {
        cout<<"Wrong position";
        exit(0);
    }
    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(Head==NULL)
        {
            Head=t;
            Head->next=Head;
        }
        else
        {
            while(p->next!=Head)
                p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    display(Head);
    Insert(Head,0,1);
    Rdisplay(Head);
    return 0;
}