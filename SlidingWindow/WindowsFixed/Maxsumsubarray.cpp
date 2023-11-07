/*Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2. */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxsumsubarray(int a[],int k,int n)
{
    int i=0,j=0;
    int sum=0;
    int mx=INT_MIN;
    while(j<n)
    {
        sum+=a[j];
        if(((j-i)+1)<k)
        {
            j++;
        }
        else
        if(((j-i)+1)==k)
        {
            mx=max(mx,sum);
            sum=sum-a[i];
            i++;
            j++;
        }
    }
    return mx;
}


int main()
{
   int a[]={100, 200, 300, 400};
    int ans=maxsumsubarray(a,2,4);

    cout<<"ans is "<<ans<<endl;
}