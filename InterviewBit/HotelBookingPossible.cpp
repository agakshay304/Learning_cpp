#include<iostream>
#include<vector>
using namespace std;

bool hotelvacancy(int a[],int n,int d[],int m,int k)
{
    sort(a,a+n);
    sort(d,d+m);
    int i=0,j=0,count=0;

    while(i<n && j<m)
    {
        if(a[i]<d[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        if(count>k)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a[]={1,3,5};
    int d[]={2,6,8};

    cout<<hostelvacancy(a,3,d,3,1);
}