#include <iostream>
using namespace std;
int setbit(int n , int pos)
{
    return (n | (1<<pos));
}

int main()
{
    int n , pos;

    cout<<"Enter No. & Position ";
    cin>>n;
    cin>>pos;
    
    cout<<setbit(n,pos)<<endl;
}