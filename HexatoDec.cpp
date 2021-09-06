#include <bits/stdc++.h>
using namespace std;

int hextod(string n)
{
    int len=n.length();
    int x=1;
    int sum=0;

    for(int i=len-1;i>=0;i++)
    {
        if(n[i]>='0' || n[i]<='9')
        {
            sum+=x*(n[i]-'0');
        }
        else
        if(n[i]>='A'  || n[i]<='F')
        {
            sum+=x*(n[i]-'A' + 10);
        }
        x*=16;

    }
    return sum;
}
int main()

{
    string n;
    cout<<"Enter HexaDecimal";
    cin>>n;

    cout<<hextod(n);
}