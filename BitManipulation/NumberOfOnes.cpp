#include <iostream>
using namespace std;

int numberofones(int n )
{
    int count=0;
    while(n)
    {
        n=n & n-1;
        count ++;
    }
    return count;
}



int main()
{
    int n;
    cout<<"Enter No to Check";
    cin>>n;

   

   cout<<numberofones(n);

    
}