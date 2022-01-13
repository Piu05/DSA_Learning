//Heap Vs Stack memory
/*
//Stack memory allocation(Organized memory)
void fun2(int i)
{
    int a;
    ....
}
void fun1()
{
    int x;
    fun2(x);
}
void main()
{
    int a;         // |
    float b;       // | Stored in stack(Portion of memory allocated automatically is called as activation record of function)
    fun1();
}
-Memory stored during compilation time is called static allocation
-When the call is moved from a function to other then its activation record is deleted
-When the program ends then all the activation record is deleted in a way of stack automatically

//Heap memory allocation(Unorganized memory)
- is treated as a resource
- programs does not access heap memory directly
- programs access it using pointer

void main()
{
    int *P;         //Allocate memory in stack
C++:    p=new int[5];     //It will allocate memory of size 5 in heap('new' is used for heap allocation)
C:      p=(int *)malloc(sizeof(int)*5);   //It will allocate memory of size 5 in heap
.
.
.
p=NULL;     //Deallocate memory if not needed
}

*/