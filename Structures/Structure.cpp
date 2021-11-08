//Structures
#include<iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
int main()
{
    //declaration
    struct rectangle r;
    //declaration and initialisation
    //Method 1
    //struct rectangle r={10,5};
    //Method 2
    r.length=10;
    r.breadth=5;
    cout<<"Area of rectangle: "<<(r.length*r.breadth)<<endl;
    return 0;
}