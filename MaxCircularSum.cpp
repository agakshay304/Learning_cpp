#include <iostream>
#include <climits>
using namespace std;
int kadane (int a[],int n)
{
    int maxsum=INT_MIN;
    int currsum=0;

    for(int i=0;i<n;i++)
    {
        currsum+=a[i];
        if(currsum<0)
        {
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }

    return maxsum;
}
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

    int wrapsum=0;
    int unwrapsum=0;

    unwrapsum=kadane(a,n);


    int totalsum=0;
    for(int i=0;i<n;i++)
    {
        totalsum+=a[i];
        a[i]=-a[i];
    }

    /*Formula 
    WrappedSum=TotalSum-noncontributingsum*/

    wrapsum=totalsum+kadane(a,n);

    cout<<max(wrapsum,unwrapsum)<<endl;

}
