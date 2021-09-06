//Update Bit is just the combination of set & clear bit.

#include <iostream>
using namespace std;
int updatebit(int n , int pos,int value)
{
    //For Clearing The Bit
    int mask=~(1<<pos);
    n=n&mask;

    //For Setting the Bit
    return (n | (value<<pos));
}

int main()
{
    int n , pos,value;

    cout<<"Enter No. & Position & Value to update ";
    cin>>n;
    cin>>pos;
    cin>>value;
    
    cout<<updatebit(n,pos,value)<<endl;
}