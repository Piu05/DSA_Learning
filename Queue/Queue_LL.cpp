//Queue using linked list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
        cout<<"Queue is full";
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
            rear->next=t;
            rear=t;
    }
}
int dequeue()
{
    int x=-1;
    Node *p;
    if(front==NULL)
        cout<<"Queue is empty";
    else
    {
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
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
int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(12);
    display(front);
    dequeue();
    dequeue();
    display(front);
    return 0;
}