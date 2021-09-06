#include <iostream>
using namespace std;
int getbit(int n , int pos)
{
    return ((n & (1<<pos))!=0);
}

int main()
{
    int n , pos;

    cout<<"Enter No. & Position ";
    cin>>n;
    cin>>pos;
    
    cout<<getbit(n,pos)<<endl;
}