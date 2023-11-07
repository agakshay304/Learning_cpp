#include "/Users/akshay/Desktop/stdc++.h";
using namespace std;


int btod(int n)
{
    int sum=0;
    int x=1;
    while(n>0)
    {
       int d=n%10;
       sum+=x*d;
       x*=2;
       n=n/10; 
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter Binary Digit ";
    cin>>n;

    int ans=btod(n);

    cout<<"Decimal is "<<ans;

    return 0;
}