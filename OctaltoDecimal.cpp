#include <iostream>
using namespace std;


int btod(int n)
{
    int sum=0;
    int x=1;
    while(n>0)
    {
       int d=n%10;
       sum+=x*d;
       x*=8;
       n=n/10; 
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter Octal Digit ";
    cin>>n;

    int ans=btod(n);

    cout<<"Decimal is "<<ans;

    return 0;
}