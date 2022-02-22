//Doubly Ended Queue
/*
-Insertion and deletion can be done using both front and rear
*/
#include<iostream>
using namespace std;
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
void enqueue(Queue *q,int x)        //Insertion from rear
{
    if(q->rear==q->size-1)
        cout<<"\nQueue is full";
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
void enqueueF(Queue *q,int x)       //Insertion from front
{
    if(q->front==-1)
        cout<<"\nQueue is full from front";
    else
    {
        q->Q[q->front]=x;
        q->front--;
    }
}
int dequeue(Queue *q)       //Deletion from front
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
int dequeueR(Queue *q)      //Deletion from rear
{
    int x=-1;
    if(q->front==q->rear)
        cout<<"\nQueue is empty";
    else
    {
        x=q->Q[q->rear];
        q->rear--;
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
    dequeue(&q);
    display(q);
    enqueueF(&q,22);   
    display(q);
    dequeueR(&q);
    display(q);
    return 0;
}