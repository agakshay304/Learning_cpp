#include <iostream>
using namespace std;


//For Checking Whether position for rat is free or possible to move.
bool issafe(int **a,int x,int y,int n)
{
    if(x<n && y<n && a[x][y]==1)
    {
        return true;
    }
    return false;
}

bool ratinmaze(int **a,int x,int y ,int n  ,int **sol)
{
    if(x==n-1 && y==n-1)
    {
        sol[x][y]=1;
        return true;
    }
    if(issafe(a,x,y,n))
    {
        sol[x][y]=1;
        if(ratinmaze(a,x+1,y,n,sol))
        {
            return true;
        }
        if(ratinmaze(a,x,y+1,n,sol))
        {
            return true;
        }
        sol[x][y]=0; //BackTracking
        return false;
    }
    return false;
}

int main()
{
    int n ;
    cout<<"Enter Size Of Matrix ";
    cin>>n;
    //This is For initialising dynamic array
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
cout<<"Enter Possible Path ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
//This is For initialising a Sol Array with 0
    int **sol=new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }
    int x=0;
    int y=0;

    if(ratinmaze(a,x,y,n,sol))
    {
       for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<"Not Possible";
    }

}

