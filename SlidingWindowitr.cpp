#include <iostream>
using namespace std;


int slidingwindow(int arr[],int n,int k,int x)
{
    int sum=0,ans=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    if(sum<x)
    {
        ans=sum;
    }

    for(int i=k;i<n;i++)
    {
        sum=sum-arr[i-k];
        sum=sum+arr[i];
        if(sum<x)
        ans=max(ans,sum);
    }

    return ans;
    
}

int main()
{
    int arr[]={7,5,4,6,8,9};
    cout<<slidingwindow(arr,6,3,20);
}