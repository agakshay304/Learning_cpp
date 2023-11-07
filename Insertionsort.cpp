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
    for(int i=0;i<n;i++)
    {
        int current=a[i];
        int j=i-1;
            if(a[j]>current)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=current;
    }
    //Printing
            cout<<"Sorted Array is:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
return 0;
}