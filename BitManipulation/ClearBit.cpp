#include <iostream>
using namespace std;
int clearbit(int n , int pos)
{
    int mask=~(1<<pos);
    return (mask & n );
}

int main()
{
    int n , pos;

    cout<<"Enter No. & Position ";
    cin>>n;
    cin>>pos;
    
    cout<<clearbit(n,pos)<<endl;
}