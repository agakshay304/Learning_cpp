#include <iostream>
using namespace std;


void swap(int a[],int i,int j)

{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void dnf(int a[],int n)
{
    int low=0;
    int mid=0;
    int high=n-1;


    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[mid],a[low]);
            mid++;
            low++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else if(a[mid]==2)
        {
            swap(a[mid],a[high]);
            high--;
        }
    }
}


int main()
{
    int a[]={1,0,0,1,2,0,2,0,1,0};

    dnf(a,10);


    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }
}