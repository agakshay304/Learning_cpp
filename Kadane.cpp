#include <iostream>
#include <climits>
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

    cout<<"Max Sum of Subarray is "<<maxsum<<endl;

    return 0;

}

//for dealing with all negative element in an array test case
/*int maxSubarraySum(int arr[], int n){
        int ksum=0;
        int maxsum=-9999999;
        int count=0;
        int big=-999999;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                count++;
            }
            if(arr[i]>big)
            {
                big=arr[i];
            }
            ksum+=arr[i];
            if(ksum<0)
            {
                ksum=0;
            }
                if(maxsum<ksum)
                {
                    maxsum=ksum;
                }
            }
            if(count == n)
            {
                return big;
            }
            else
            {
        return maxsum;
    }
    }*/