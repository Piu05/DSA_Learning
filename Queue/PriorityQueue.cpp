//Priority queue for Upper case and Lower case alphabets
#include<iostream>
using namespace std;
class Node
{
    public:
    char data;
    Node *next;
};
class que
{
    Node *front;
    Node *rear;
    public:
    que()
    {
        front=rear=NULL;
    }
    ~que()
    {
        Node *p=front;
        while(front)
        {
            front=front->next;
            delete p;
            p=front;
        }
    }
    int isEmpty();
    void enqueue(char e);
    char dequeue();
    void display();
};
int que::isEmpty()
{
    if(front==NULL)
        return 1;
    return 0;
}
void que::enqueue(char e)
{
    Node *t;
    t=new Node;
    t->data=e;
    if(front==NULL)
    {
        t->next=NULL;
        front=t;
        rear=t;
        return;
    }
    t->next=NULL;
    rear->next=t;
    rear=t;
}
char que::dequeue()
{
    char x='\0';
    if(front==NULL)
        return x;
    x=front->data;
    Node *p=front;
    front=front->next;
    delete p;
    return x;
}
void que::display()
{
    Node *p=front;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int getPriority(char x)
{
    if(x>=65 && x<=90)
        return 1;
    if(x>=97 && x<=122)
        return 2;
    return 0;
}
void enqP(que *q1, que *q2,char x)
{
    int P=getPriority(x);
    if(P==1)
        q1->enqueue(x);
    if(P==2)
        q2->enqueue(x);
}
char deqP(que *q1, que *q2)
{
    char x='\0';
    if(!q1->isEmpty())
        x=q1->dequeue();
    else if(!q2->isEmpty())
        x=q2->dequeue();
    return x;
}
int main()
{
    que q1,q2;
    enqP(&q1,&q2,'A');
    enqP(&q1,&q2,'B');
    enqP(&q1,&q2,'c');
    enqP(&q1,&q2,'d');
    enqP(&q1,&q2,'E');
    q1.display();
    q2.display();
    cout<<deqP(&q1,&q2)<<endl;
    cout<<deqP(&q1,&q2)<<endl;
    cout<<deqP(&q1,&q2)<<endl;
    cout<<deqP(&q1,&q2)<<endl;
    return 0;
}