#include <iostream>
using namespace std;
//LIFO
#define n 100
template <class T>
class arrofstack
{
int* a;
int top;
public:
arrofstack()
{
    a=new int[n];
    top=-1;
}


void push(int x)
{
    if(top==n-1)
    {
        cout<<"Stack OverFlowed";
        return ;
    }

    top++;
    a[top]=x;
}

void pop()
{
    if(top==-1)
    {
        cout<<"Nothing to be popped";
        return ;
    }
    top--;
}

int Top()
{
    if(top==-1)
    {
        cout<<"Stack is Empty";
        return -1;
    }

    return a[top];
}

bool empty()
{
    return top==-1;
}
};

int main()
{
    arrofstack ob;
    ob.push(1);
    ob.push(2);
    ob.push(3);
    ob.push(4);
   cout<< ob.Top()<<endl;
    ob.pop();
    cout<< ob.Top()<<endl;
    ob.pop();
    ob.pop();
    ob.pop();
    cout<< ob.empty();
}


