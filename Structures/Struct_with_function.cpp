//Perfect method for C
#include<iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void initialize(Rectangle *r,int l,int b)
{
    r->length=l;
    r->breadth=b;
}
int area(Rectangle r)
{
    return r.length*r.breadth;
}
void changeLength(Rectangle *r,int l)
{
    r->length=l;
}
int main()
{
    struct Rectangle r;
    initialize(&r,10,5);
    cout<<"Area="<<area(r);
    changeLength(&r,20);
    cout<<"\nNew Area="<<area(r);
}

//Changes to make it C++ (OOP Concept)
class Rectangle
{
    int length;
    int breadth;
    public:
    void initialize(int l,int b)
    {
        length=l;
        breadth=b;
    }
    int area()
    {
        return length*breadth;
    }
    void changeLength(i)nt l)
    {
        length=l;
    }
};
int main()
{
    Rectangle r;
    r.initialize(10,5);
    cout<<"Area="<<r.area();
    r.changeLength(20);
    cout<<"\nNew Area="<<r.area();
}
//We can use constructor to avoid using initialize function
class Rectangle
{
    int length;
    int breadth;
    public:
    Rectangle(int l,int b)
    {
        length=l;
        breadth=b;
    }
    int area()
    {
        return length*breadth;
    }
    void changeLength(i)nt l)
    {
        length=l;
    }
};
int main()
{
    Rectangle r(10,5);
    cout<<"Area="<<r.area();
    r.changeLength(20);
    cout<<"\nNew Area="<<r.area();
}