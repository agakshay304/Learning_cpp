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
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
        //Printing
            cout<<"Sorted Array is:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
return 0;
}