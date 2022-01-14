//Template Class
//It is used to make variables used as any data type 
//int a can store int values only, this drawback can be corrected using template class 
#include<iostream>
using namespace std;
template<class T>
class Numbers
{
    T a;
    T b;
    public:
    Numbers(T a,T b);
    T add();
    T sub();
};
    template<class T>
    Numbers<T>::Numbers(T a,T b)
    {
        this->a=a;  //here 'this' is used to access 'a' of class
        this->b=b;
    }
    template<class T>
    Numbers<T>::add()
    {
        T c;
        c=a+b;
        return c;
    }
    template<class T>
    Numbers::sub()
    {
        T c;
        c=a-b;
        return c;
    }
int main()
{
    Numbers<int> n1(20,10);
    cout<<"Sum="<<n1.add();
    cout<<"\nDifference="<<n1.sub();
    Numbers<float> n2(10.5,5.2);
    cout<<"Sum="<<n2.add();
    cout<<"\nDifference="<<n2.sub();
    return 0;
}
