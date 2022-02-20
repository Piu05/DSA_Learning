#include<iostream>
#include<cstring>
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
int isOperand(char s)
{
    if(s>='0' &&s<='9')     //For only conversion use 'a' and 'z' instead of '0' and '9'
        return 1;
    else
        return 0;
}
int pre(char s)
{
    if(s=='*'||s=='/')
        return 2;
    else if(s=='+'||s=='-')
        return 1;
    else
        return 0;
}
int Eval(char *postfix)
{
    int i=0;
    int x,y,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            y=pop();
            x=pop();
            switch(postfix[i])
            {
                case '+':r=x+y; break;
                case '-':r=x-y; break;
                case '*':r=x*y; break;
                case '/':r=x/y; break;
            }
            push(r);        
        }
    }
    return top->data;
}
int main()
{
    char infix[]="234*+82/-";
    cout<<"Result="<<Eval(infix);   
    return 0;
}