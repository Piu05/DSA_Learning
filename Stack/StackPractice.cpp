//Paranthesis Matching  (Check if expression has equal no. of opening and closing bracket)
#include<iostream>
#include<string>
using namespace std;
struct Node
{
    char data;
    Node *next;
}*top=NULL;
void push(char x)
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
char pop()
{
    Node *t;
    char x=-1;
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
int isEmpty()
{
    if(top==NULL)
        return 1;
    return 0;
}
int isBalanced(string exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {   if(top==NULL)
                return 0;
            else
                pop();
        }
            
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}
int main()
{
    string exp="(((a+b)*c)+d)";
    if(isBalanced(exp))
        cout<<"Paranthesis are balanced";
    else    
        cout<<"Not balanced";
    return 0;
}

//NOTE: For checking diff. types of brackets include them during comparison