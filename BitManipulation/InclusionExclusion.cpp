#include <iostream>
using namespace std;


int inex(int n ,int a,int b)
{
    int c1=n/a;
    int c2=n/b;

    int c3=n/(a*b);

    return c1+c2-c3;
}

int main()
{
    int n,a,b;
    cout<<"Enter Number and limit";
    cin>>n>>a>>b;

    cout<<inex(n,a,b);
}