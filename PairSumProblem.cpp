#include <iostream>
using namespace std;

int main()
{
    int n,k ;
    cout<<"Enter Size Of Array ";
    cin>>n;

    cout<<"Enter Value Of K ";
    cin>>k;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //Sorting

    int counter=1;
    while(counter<n)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(a[i+1]<a[i])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
        counter++;
    }

    int st=0,end=n-1;
    int sum=0;
    int temp=0;

    while(st<end)
    {
        sum=a[st]+a[end];
        if(sum==k)
        {
            cout<<a[st]<<" "<<a[end];
            temp=1;
            break;
        }
        else
        if(sum>k)
        {
            end--;
        }
        else
        {
            st++;
        }
    }
    if(temp==0)
    {
        cout<<"Sum Not Possible";
    }
}
