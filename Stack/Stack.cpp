//Stack Using Array
/*
Uses LIFO (time complexity O(1))
ADT stack
    -Data 
    1.Space for string elements
    2.Top pointer
    -Operations
    1.push(x)
    2.pop()
    3.peek(index)
    4.stackTop()
    5.isEmpty()
    6.isFull()
*/
#include<iostream>
using namespace std;
//Stack declaration
struct Stack
{
    int size;
    int top;
    int *S;
};
//Create function
void create(Stack *st)
{
    cout<<"Enter size:";
    cin>>st->size;
    st->top=-1;
    st->S=new int;
}
void display(Stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
}
void push(Stack *st,int x)
{
    if(st->top==st->size-1)
        cout<<"Stack Overflow\n";
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
int pop(Stack *st)
{
    int x=-1;
    if(st->top==-1)
        cout<<"Stack Underflow\n";
    else
        x=st->S[st->top--];
    return x;
}
int peek(Stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
        cout<<"Invalid index\n";
    x=st.S[st.top-index+1];
    return x;
}
int isEmpty(Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
int isFull(Stack st)
{
    if(st.top==st.size-1)
        return 1;
    return 0;
}
int stackTop(Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}
int main()
{
    Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    display(st);
    cout<<peek(st,3)<<endl;
    cout<<isFull(st)<<endl;
    cout<<isEmpty(st)<<endl;
    cout<<stackTop(st)<<endl;
    cout<<pop(&st)<<endl;
    display(st);
    return 0;
}