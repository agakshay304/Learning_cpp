#include <iostream>
using namespace std;

int firstoc(int a[],int n,int key,int i)
{
if(i==n)
{
    return -1;
}

if(a[i]==key)
{
    return i;
}
return firstoc(a,n,key,i+1);
}

int lastoc(int a[],int n,int key,int i)
{

    if(i==n)
    return -1;
  int restarray=lastoc(a,n,key,i+1);
  if(restarray !=-1)
      return restarray;
    if(a[i]==key)
    {
        return i;
    }
    return -1;
}




int main()
{
    int a[]={1,2,3,5,2,7,8,2,4,1};
    int k,i;
        cout<<"Enter Key ";
        cin>>k;

       cout<< firstoc(a,10,k,i)<<endl;
       cout<<lastoc(a,10,k,i)<<endl;
    return 0;
}
