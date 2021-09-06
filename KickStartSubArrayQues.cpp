#include <iostream>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter Size Of Array ";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int ans=2;
    int pd=a[0]-a[1];
    int j=2;
    int curr=2;

    while(j<n)
    {
        if(pd==a[j+1]-a[j])
        {
            curr++;
        }
        else
        {
            pd=a[j+1]-a[j];
            curr=2;
        }
        ans=max(ans,curr);
        j++;
    }

    cout<<ans<<endl;


}
