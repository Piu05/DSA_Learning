//Queue
/*
-Follows FIFO (First In First Out)
-Insertion from rear end and deletion from front end
-Queue ADT
Data
    -Space for storing elements
    -Front
    -Rear
Operations
    -enqueue(x)
    -dequeue()
    -isEmpty()
    -isFull()
    -first()
    -last()
*/
#include<iostream>
using namespace std;
//Queue using array
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int[size];
}
void enqueue(Queue *q,int x)
{
    if(q->rear==q->size-1)
        cout<<"\nQueue is full";
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        cout<<"\nQueue is empty";
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    display(q);
    dequeue(&q);
    display(q);
    return 0;
}

//In C++, queue can be implemented using class:
/*class Queue
{
    int size;
    int front;
    int rear;
    int *Q;
    public:
    Queue(){front=rear=-1;  size=10;    Q=new int[size];}
    Queue(int size){front=rear=-1;  this->size=size;    Q=new int[this->size]; }
    void enqueue(int x);
    int dequeue();
    void display();
};
void Queue::enqueue(int x)
{
    if(rear==size-1)
        cout<<"\nQueue is full";
    else
    {
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{
    int x=-1;
    if(front==rear)
        cout<<"\nQueue is empty";
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}
void Queue::display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
*/