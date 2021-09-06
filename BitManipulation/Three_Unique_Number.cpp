#include <iostream>
using namespace std;

bool getbit(int n,int pos )
{
    return ((n & (1<<pos))!=0);
}

int setbit(int n,int pos)
{
    return (n | (1<<pos));
}

int unique(int a[],int n )
{
    int result=0;
 for(int i=0;i<64;i++)//This is for storing the numbers having same position set bits.
 {
     int sum=0;
     for(int j=0;j<n;j++)//This is for iterating to each number
     {
         if(getbit(a[j],i))
         {
             sum++;
         }
     }
     if(sum%3 !=0)
     {
         result=setbit(result,i);
     }
    
 }
  return result;   
}
int main()
{
    int a[]={1,1,1,2,3,3,2,3,2,4};
    cout<<unique(a,10);
    return 0;
}