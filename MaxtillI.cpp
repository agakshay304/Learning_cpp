#include <iostream>
using namespace std;

int main()
{
    int mx;
    mx=-1999999999;
    int n ;
    cout<<"Enter Size Of Array ";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[i]);
        cout<<mx<<endl;
    }
}