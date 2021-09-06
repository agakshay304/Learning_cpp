#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool ispalin(int num)
{
    int temp=num;
    int rev=0;
    int d=0;
    while(temp>0)
    {
        d=temp%10;
        rev=rev*10+d;
        temp=temp/10;
    }
    if(rev==num)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int checkpalin(vector<int> a,int k)
{
    int num=0;
    for(int i=0;i<k;i++)
    {
        num=num*10+a[i];
    }
    if(ispalin(num))
    {
        return 0;
    }
    for(int j=k;j<a.size();j++)
    {
        num=(num % (int)pow(10,k-1))*10+a[j];
        if(ispalin(num))
        {
            return j-k+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);
    a.push_back(1);
    a.push_back(5);
    int k=4;
    int ans=checkpalin(a,k);

    if(ans==-1)
    {
        cout<<"Not Possible";
    }
    else
    {
        for(int i=ans;i<ans+k;i++)
        {
            cout<<a[i];
        }
    }
}