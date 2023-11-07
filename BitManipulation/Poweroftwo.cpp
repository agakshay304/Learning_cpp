#include <iostream>
using namespace std;

bool poweroftwo(int n )
{
    return (n && !(n & n-1));
}



int main()
{
    int n;
    cout<<"Enter No to Check";
    cin>>n;

    cout<<poweroftwo(n)<<endl;

    
}