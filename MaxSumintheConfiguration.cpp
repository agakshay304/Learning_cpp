// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
int sum=0,s0=0;
for(int i=0;i<N;i++)
{
    sum+=A[i];
    s0+=A[i]*i;
}
int si=s0;
int max=s0;

for(int i=0;i<N-1;i++)
{
    int sip=si+sum-N*A[N-1-i];
    if(sip>max)
    {
        max=sip;
    }
    si=sip;
}
return max;
}