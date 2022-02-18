//Stack using linked list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*top=NULL;
void display()
{
    Node *p;
    p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void push(int x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
        cout<<"Stack Overflow\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop()
{
    Node *t;
    int x=-1;
    if(top==NULL)
        cout<<"Stack Underflow\n";
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}
int peek(int index)
{
    int x=-1;
    Node *p;
    p=top;
    for(int i=0;p!=NULL && i<index-1;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
        return p->data;
    else
        return -1;
}
int isEmpty()
{
    if(top)
        return 1;
    return 0;
}
int isFull()
{
    return 0;
}
int stackTop()
{
    if(!isEmpty())
        return;
    return -1;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();
    cout<<peek(3)<<endl;
    cout<<isFull()<<endl;
    cout<<isEmpty()<<endl;
    cout<<stackTop()<<endl;
    return 0;
}