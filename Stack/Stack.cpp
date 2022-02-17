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


}
int main()
{
    Stack st;
    return 0;
}