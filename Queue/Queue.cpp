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