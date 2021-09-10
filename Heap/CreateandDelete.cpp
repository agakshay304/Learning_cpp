#include <iostream>
using namespace std;


void insert(int a[],int n)
{
    int temp=a[n];
    int i=n;

    while(i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int deleteheap(int a[],int n)
{
    int x=a[n];
    int val=0;
    val=a[1];
    a[1]=a[n];
    int i=1,j=2*i;
    a[n]=val;
    while(j<n-1)
    {
        if(a[j+1]>a[j])
        {
            j=j+1;
        }
        if(a[i]<a[j])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;

            i=j;
            j=j*2;
        }
        else
        {
            break;
        }
    }
return val;

}


int main()
{
    int h[]={0,10,20,30,25,5,40,35};

    for(int i=2;i<=7;i++)
    {
        insert(h,i);
    }
    // int del=deleteheap(h,7);
    // cout<<"Deleted Number is "<<del<<endl;

    //Heap Sort is just deleting all the element from heap and
    //inserting it again at the last.

    for(int i=7;i>=1;i--)
    {
        deleteheap(h,i);
    }

    for(int i=1;i<=7;i++)
    {
        cout<<h[i]<<" ";
    }

    
}