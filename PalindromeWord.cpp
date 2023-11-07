#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number Of Characters in Array: ";
    cin>>n;

    char a[n+1];
    cin>>a;

    bool check=1;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[n-1-i])
        {
            check=0;
            break;
        }
    }

    if(check==1)
    {
        cout<<"The Word is Palindrome";
    }
    else
    {
        cout<<"Word is not Palindrome";
    }
    return 0;
}