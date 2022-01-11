#include<iostream>
using namespace std;
//Syntax and basic functions in class
class Rectangle
{
    int length;
    int breadth;
    public:
    Rectangle()
    {
        length=breadth=1;
    }
    Rectangle(int l,int b);
    int area();
    int perimeter();
    int getLength()
    {
        return length;
    }
    void setLength(int l)
    {
        length=l;
    }
    ~Rectangle();
};
Rectangle::Rectangle(int l,int b)
{
    length=l;
    breadth=b;
}
int Rectangle::area()
{
    return length*breadth;
}
int Rectangle::perimeter()
{
    return 2*(length+breadth);
}
Rectangle::~Rectangle()
{ }
int main()
{
    Rectangle r(10,5);
    cout<<"Area="<<r.area();
    cout<<"\nPerimeter="<<r.perimeter();
    r.setLength(20);
    cout<<"\nAfter changing length, area="<<r.area();
    return 0;
}