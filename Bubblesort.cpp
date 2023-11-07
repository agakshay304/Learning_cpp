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
    //Printing
            cout<<"Sorted Array is:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
return 0;
}