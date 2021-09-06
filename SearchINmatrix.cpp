#include <iostream>
using namespace std;
int main()
{
    int n,m,k;
    cout<<"Enter No. of Rows And Coloumns: ";
    cin>>n>>m;
    cout<<"Enter Key ";
    cin>>k;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    bool found=false;
    int r=0,c=m-1;
    while(r<n && c>=0)
    {
        if(a[r][c]==k)
        {
            found=true;
            break;
        }
        else
        if(a[r][c]>k)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if(found==true)
    {
        cout<<"Number Found at "<<r<<","<<c;
    }
    else
    {
        cout<<"Sorry Number Not Found In Matrix";
    }
}
