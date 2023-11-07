#include <iostream>
using namespace std;


int search(int a[],int n,int k)
{
    int start=0;
    int end=n-1;
    int mid=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(a[mid]==k)
        {
            return mid;
        }
        //First Check Left side or Right Side which is Strictly increasing.
        if(a[mid]>=a[start])
        {
            if(a[start]<=k && a[mid]>=k)
            {
                end=mid-1;
            }
            else
            {
            start=mid+1;
            }
        }
        //if array is strictly increassing from right side
        else
        {
            if(a[mid]<=k  && a[end]>=k)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int a[]={3,4,5,1,2};
    int n=5;
    cout<<search(a,n,6);
}